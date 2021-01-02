// 普通（非模板）类的成员模板
#include <iostream>

using namespace std;

class A
{
public:
	template <typename T2>
	void func(T2 t);
};

template <typename T2>
void A::func(T2 t)
{
	cout << t << endl;
}

int main()
{
	A a;
	a.func("hello");
	a.func(2021);
	return 0;
}



// tips:
//	1. 一个类（无论是普通类还是类模板）可以包含本身是模板的成员函数。这种成员被称为成员模板（member template）。
//	2. 成员模板不能是虚函数。