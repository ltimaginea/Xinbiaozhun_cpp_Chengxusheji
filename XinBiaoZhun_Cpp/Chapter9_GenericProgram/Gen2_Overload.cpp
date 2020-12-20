#include <iostream>

using namespace std;

template <typename T>
void Max(T a, T b)
{
	cout << "Template Max1" << "\t";
	if (a < b)
		cout << b << endl;
	else
		cout << a << endl;
}

template  <typename T>
void Max(T* a, T* b)
{
	cout << "Template Max2" << "\t";
	if (*a < *b)
		cout << *b << endl;
	else
		cout << *a << endl;
}

template <typename T1,typename T2>
void Max(T1 a, T2 b)
{
	cout << "Template Max3" << "\t";
	if (a < b)
		cout << b << endl;
	else
		cout << a << endl;
}

void Max(double a, double b)
{
	cout << "Function Max" << "\t";
	if (a < b)
		cout << b << endl;
	else
		cout << a << endl;
}

int main()
{
	int i = 4, j = 5;
	double m = 4.1, n = 5.1;
	Max(m, n);				// 输出 Function Max    5.1
	Max(i, j);				// 输出 Template Max1   5
	Max(&m, &n);				// 输出 Template Max2   5.1
	Max(m, i);				// 输出 Template Max3   4.1
	
	return 0;
}



// tips:
//	1. 函数模板可以重载，只要它们的形参表不同即可。
//	2. 在有多个函数和函数模板名字相同的情况下，一条函数调用语句到底应该被匹配成对哪个函数或模板的调用呢？C++编译器遵循以下先后顺序：
//	(1) 先找参数完全匹配的普通函数（非由模板实例化得到的函数）。
//	(2) 再找参数完全匹配的模板函数。
//	(3) 如果存在多个完全匹配的模板函数，则最具体的模板函数优先。——“最具体”指编译器推断使用哪种类型时执行的转换最少。
//	(4) 再找实参经过自动类型转换后能够匹配的普通函数。
//	(5) 如果有多个同样合适的非模板函数或模板函数，但没有一个函数比其他函数更具体，则函数调用将是不确定的，二义性的，则报错；当然，如果不存在匹配的函数，则也报错。
//	3. 示例中，第二个Max模板函数相比第一个Max模板函数更具体，它做了更具体的假设，比较内容为指针。
//	如果删除掉第二个Max模板函数，编译器将使用第一个Max模板函数来处理 "Max(&m, &n);" ，它比较和cout输出的内容将为地址，而不是值。