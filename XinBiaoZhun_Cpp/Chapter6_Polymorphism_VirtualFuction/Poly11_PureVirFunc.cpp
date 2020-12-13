#include <iostream>

using namespace std;

class CBase
{
public:
	int i;
	virtual void f() = 0;
	void func() { f(); }
	CBase() { /* 错误！ f(); */ }
	~CBase() { /* 错误！ f(); */ }
};

class CDerived :public CBase
{
public:
	int j;
	void f() { cout << "CDerived::f()" << endl; }
};

int main()
{
	CDerived derived;
	derived.func();			// 输出 CDerived::f()
	return 0;
}



// tips:
//	1. 在抽象类的成员函数内可以调用纯虚函数，但是在其构造函数或析构函数内部不能调用纯虚函数。
//	因为普通成员函数内调用纯虚函数可以发生多态，但是构造、析构函数内不会发生多态，纯虚函数又没有函数体，所以会出错。
//	2. 包含纯虚函数的类叫抽象类。抽象类只能作为基类来派生新类使用，不能创建独立的抽象类的对象。抽象类的指针和引用可以指向由抽象类派生出来的类的对象。
//	3. 如果一个类从抽象类派生而来，那么当且仅当它实现了基类中的所有纯虚函数，它才能成为非抽象类。