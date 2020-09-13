// 友元关系不能传递,但是可以多级递进友元关系

#include <iostream>

using namespace std;

class CEngine
{
private:
	int enginePrice;
public:
	CEngine() :enginePrice(1) {}
	friend class CCar;					// 声明 CCar 为友元类
};
class CCar
{
private:
	CEngine engine;
	void PrintEnginePrice();
	friend class CDriver;				// 声明 CDriver 为友元类
};
class CDriver
{
public:
	CCar myCar;
	void PrintPrice();
};
void CDriver::PrintPrice()
{
	myCar.PrintEnginePrice();
	//cout << myCar.engine.enginePrice << endl;		// 错误！不能在CDriver类的成员函数中访问CEngine类的私有成员，除非直接在CEngine类中声明CDriver类为友元。
}
void CCar::PrintEnginePrice()
{
	cout << engine.enginePrice << endl;
}

int main()
{
	CDriver driver;
	driver.PrintPrice();		// 通过多级递进友元关系，driver 对象打印出了 CEngine 类的私有成员 enginePrice 的值为 1
	return 0;
}

// tips: 
//   1. 虽然友元关系不能传递,但是可以多级递进友元关系。
//   2. 友元关系不能传递，即类A是类B的友元，类B是类C的友元，并不能导出类A是类C的友元。
//      “咱俩是朋友，所以你的朋友就是我的朋友”这句话在C++ 的友元关系上不成立。