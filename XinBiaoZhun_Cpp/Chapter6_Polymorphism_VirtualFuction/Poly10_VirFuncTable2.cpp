#include <iostream>

using namespace std;

class CBase
{
public:
	int i;
	virtual void func() { cout << "CBase::func()" << endl; }
};

class CDerived :public CBase
{
public:
	int j;
	virtual void func() { cout << "CDerived::func()" << endl; }
};

int main()
{
	CBase base;
	CDerived derived;
	CBase* ptr = &derived;
	ptr->func();					// 输出 CDerived::func()
	// 64位程序指针大小为8字节
	long long* p1 = (long long*)&base;
	long long* p2 = (long long*)&derived;
	*p2 = *p1;
	ptr->func();					// 输出 CBase::func()
	return 0;
}



// tips:
//	1. 示例程序便可以证明，多态类对象存储空间的最前端，其中存放的就是虚函数表的地址。
//	程序中，将derived对象的前8个字节(存放的是CDerived类的虚函数表地址)替换为了base对象的前8个字节的内容(存放的是CBase类的虚函数表地址)，最后derived对象的前8个字节存放的便是CBase类的虚函数表地址。
//	所以之后第29行发生多态时，查到的会是CBase类的虚函数表，所以最后执行的就是CBase::func() 。
//	2. 通常，编译器处理虚函数的方法是：给每个对象添加一个隐藏成员(位于对象存储空间的最前端)。隐藏成员中保存了一个指向函数地址数组的指针。
//	这种数组称为虚函数表（virtual function table，vtbl）。虚函数表中存储了为类对象进行声明的虚函数的地址。