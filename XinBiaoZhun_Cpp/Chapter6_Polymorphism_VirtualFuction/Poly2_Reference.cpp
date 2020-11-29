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

void PrintInfo(A& r)
{
	r.Print();		// 多态，调用哪个Print，取决于r引用了哪个类的对象
}

int main()
{
	A a; B b; D d; E e;
	PrintInfo(a);		// 输出 A::Print
	PrintInfo(b);		// 输出 B::Print
	PrintInfo(d);		// 输出 D::Print
	PrintInfo(e);		// 输出 E::Print
	return 0;
}



// tips:
//	1. 注意类E，即使Print()是private，编译依然可以通过，多态时也能正确调用E::Print()