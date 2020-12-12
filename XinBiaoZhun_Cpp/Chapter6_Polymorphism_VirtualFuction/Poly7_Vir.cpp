#include <iostream>

using namespace std;

class A
{
public:
	void func1() { cout << "A::func1" << endl; }
	virtual void func2() { cout << "A::func2" << endl; }
};

class B :public A
{
public:
	virtual void func1() { cout << "B::func1" << endl; }
	void func2() { cout << "B::func2" << endl; }			// 自动成为虚函数
};

class C :public B
{
public:
	void func1() { cout << "C::func1" << endl; }			// 自动成为虚函数
	void func2() { cout << "C::func2" << endl; }			// 自动成为虚函数
};

int main()
{
	C obj;
	A* pa = &obj;
	B* pb = &obj;
	pa->func2();		// 输出 C::func2
	pa->func1();		// 输出 A::func1
	pb->func1();		// 输出 C::func1
	return 0;
}



// tips:
//	1. 基类中的某个函数被声明为虚函数，则派生类中的同名、同参数表的成员函数即使前面不写virtual关键字，也自动成为虚函数。