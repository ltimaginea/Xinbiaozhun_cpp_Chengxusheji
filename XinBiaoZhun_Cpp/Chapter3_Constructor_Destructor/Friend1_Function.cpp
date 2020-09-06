// 友元函数

#include <iostream>

using namespace std;

class CCar;				// 提前声明 CCar 类，以便后面的 CDriver 类使用
class CDriver
{
public:
	void ModifydCar(CCar* pCar);
private:
	void PrintInfo();
};
class CCar
{
private:
	int price;
	friend int MostExpensiveCar(CCar cars[], int total);			// 声明友元
	friend void CDriver::ModifydCar(CCar* pCar);				// 声明友元
	//friend void CDriver::PrintInfo();					// 错误！不能把其他类的私有成员函数声明为友元，编译时会提示“无法访问该私有成员”
};
void CDriver::ModifydCar(CCar* pCar)
{
	pCar->price += 1000;
}
int MostExpensiveCar(CCar cars[], int total)
{
	int maxPrice = -1;
	for (int i = 0; i < total; ++i)
	{
		if (cars[i].price > maxPrice)
			maxPrice = cars[i].price;
	}
	return maxPrice;
}

int main()
{
	return 0;
}

// tips: 
//   1. 友元分为友元函数和友元类。
//   2. 定义一个类时，可以把一些函数(包括全局函数和其他类的成员函数)声明为“友元”(友元函数)，这样在友元函数内部就可以访问该类对象的私有成员。
//   3. 注意，不能把其他类的私有成员函数声明为友元。编译时会提示“无法访问该私有成员”。
//   4. 友元关系不能传递。
//   5. 可以简单地将一个类的名字提前声明，以便在该类的定义出现之前使用使用该类，如第7行的提前声明和第11行的使用。
//      尽管可以提前声明，但是在一个类的定义出现之前，仍然不能有任何导致该类对象被生成的语句。但使用该类的指针或引用是没有问题的。
//   6. 第18行将MostExpensiveCar函数声明为CCar的友元函数。这条语句本来就是在声明MostExpensiveCar是一个函数，所以CCar类定义前面就不用声明MostExpensiveCar函数了。