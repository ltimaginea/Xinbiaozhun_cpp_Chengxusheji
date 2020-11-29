#include <iostream>

using namespace std;

class A
{
public:
	virtual void Print() { cout << "A::Print" << endl; }
};
class B :public A
{
public:
	virtual void Print() { cout << "B::Print" << endl; }
};
class D :public A
{
public:
	virtual void Print() { cout << "D::Print" << endl; }
};
class E :public B
{
//public:	/* 即使是private，编译依然可以通过，多态时也能正确调用E::Print() */
private:
	virtual void Print() { cout << "E::Print" << endl; }
};

int main()
{
	A a; B b; D d; E e;
	A* pa = &a; B* pb = &b;
	pa->Print();	// 输出 A::Print
	pa = pb;
	pa->Print();	// 输出 B::Print
	pa = &d;
	pa->Print();	// 输出 D::Print
	pa = &e;
	pa->Print();	// 输出 E::Print
	return 0;
}



// tips:
//	1. 多态的函数调用语句被称为是“动态联编”的，而普通的函数调用语句是“静态联编”的。
//	2. 注意类E，即使Print()是private，编译依然可以通过，多态时也能正确调用E::Print()