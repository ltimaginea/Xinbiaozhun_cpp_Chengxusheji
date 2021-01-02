// 类模板的成员模板
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class A
{
private:
	T a;
public:
	template <typename T2>
	void func(T2 t);
};

template <typename T>		// 类模板的类型参数
template <typename T2>		// 成员模板的类型参数
void A<T>::func(T2 t)
{
	cout << t << endl;
}

int main()
{
	A<int> a;
	a.func("hello");
	a.func(2021);
	return 0;
}



// tips:
//	1. 一个类（无论是普通类还是类模板）可以包含本身是模板的成员函数。这种成员被称为成员模板（member template）。
//	2. 成员模板不能是虚函数。
//	3. 对于类模板，我们也可以为其定义成员模板。在此情况下，类和成员各自有自己的、独立的模板参数。
//	4. 当我们在类模板外定义一个成员模板时，必须同时为类模板和成员模板提供模板参数列表。类模板的参数列表在前，后跟成员自己的模板参数列表。