#include <iostream>

using namespace std;

class CBase
{
public:
	void func1()
	{
		func2();
	}
	virtual void func2() { cout << "CBase::func2()" << endl; }
};

class CDerived :public CBase
{
public:
	virtual void func2() { cout << "CDerived::func2()" << endl; }
};

int main()
{
	CDerived d;
	d.func1();			// 输出 CDerived::func2()
	return 0;
}



// tips:
//	1. 在成员函数(静态成员函数、构造函数和析构函数除外)中调用其他虚成员函数的语句是多态的。
//	2. 第24行调用func1成员函数，进入func1成员函数，执行到第10行，调用func2函数。看起来调用的应该是CBase类的func2成员函数，但输出结果证明实际上调用的是CDerived类的func2成员函数。
//	这是因为，在func1函数中，"func2();"等价于"this->func2();"，而this指针显然是 CBase* 类型的，即是一个基类指针，那么"this->func2();"就是在通过基类指针调用虚函数，
//	因此这条函数调用语句是多态的。当本程序执行到第10行时，this指针指向的是一个CDerived类的对象，即d，因此被调用的就是CDerived类的func2成员函数。