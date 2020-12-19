#include <iostream>

using namespace std;

template <typename T>		// 或者 template <class T>
void Swap(T& x, T& y);

int main()
{
	int n = 1, m = 2;
	Swap(m, n);
	cout << "n=" << n << " " << "m=" << m << endl;
	double f = 1.2, g = 2.5;
	Swap(f, g);
	cout << "f=" << f << " " << "g=" << g << endl;
	return 0;
}

template <typename T>
void Swap(T& x, T& y)
{
	T tmp;
	tmp = x;
	x = y;
	y = tmp;
}

// tips:
//	1. 泛型程序设计是一种算法在实现时不指定具体要操作的数据的类型的程序设计方法。
//	2. 在 C++ 中，模板分为函数模板和类模板两种。
//	3. 一个模板参数名的可用范围是在其声明之后，至模板声明或定义结束之前。
//	4. 函数模板和类模板成员函数的定义通常放在头文件中。
//	5. typename 和 class 可以互换使用，推荐使用 typename ，更直观。
//	6. 编译器由模板自动生成函数时，会用具体的类型名对模板中所有的类型参数进行替换，其他部分则原封不动地保留。
//	7. 编译器由模板自动生成函数的过程叫模板的实例化。由模板实例化而得到的函数称为模板函数。