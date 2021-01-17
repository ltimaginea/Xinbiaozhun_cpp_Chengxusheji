// 默认模板实参

#include <iostream>

using namespace std;

template <typename T = int>
class CNumbers
{
public:
	CNumbers(T val_ = 0) :val(val_) {}
private:
	T val;
};

// 我们为此模板参数提供了默认实参，并为其对应的函数参数也提供了默认实参
template <typename T1, typename T2 = const char*>
void Print(T1 a, T2 b = "Parameter")
{
	cout << a << "\t" << b << endl;
}

int main()
{
	CNumbers<double> n1;
	Print(23, 23.3);				// 输出 23      23.3

	// 用空<>表示我们希望使用默认类型
	CNumbers<> n2;
	Print(233);					// 输出 233     Parameter
	return 0;
}



// tips:
//	1. 在新标准中，我们可以为函数模板和类模板提供默认实参，而更早的C++标准只允许为类模板提供默认实参。
//	2. 与函数默认实参一样，对于一个模板参数，只有当它右侧的所有参数都有默认实参时，它才可以有默认实参。
//	3. 如果一个类模板为其所有模板参数都提供了默认实参，且我们希望使用这些默认实参，就必须在模板名之后跟一个空尖括号对<> 。