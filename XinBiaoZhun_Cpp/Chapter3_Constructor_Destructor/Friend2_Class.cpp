// 友元类

#include <iostream>

using namespace std;

class CCar
{
private:
	int price;
	friend class CDriver;				// 声明 CDriver 为友元类
};
class CDriver
{
public:
	CCar myCar;
	void ModifyCar();
};
void CDriver::ModifyCar()
{
	myCar.price += 1000;				// 因为 CDriver 是 CCar 的友元类，故此处可以访问其私有成员
}

int main()
{
	return 0;
}

// tips: 
//   1. 一个类A可以将另一个类B声明为自己的友元，这样类B的所有成员函数(包括私有)就都可以访问类A对象的私有成员。
//   2. 友元关系不能传递，即类A是类B的友元，类B是类C的友元，并不能导出类A是类C的友元。
//   2. 第11行将CDriver声明为CCar的友元类。这条语句本来就是在声明CDriver是一个类，所以CCar类定义前面就不用声明CDriver类了。