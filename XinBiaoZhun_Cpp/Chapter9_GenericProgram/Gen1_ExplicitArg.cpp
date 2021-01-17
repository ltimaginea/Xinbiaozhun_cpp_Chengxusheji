#include <iostream>

using namespace std;

template <typename T>
int Compare(T a, T b)
{
	if (a < b)
		return -1;
	else if (b < a)
		return 1;
	else
		return 0;
}

template <typename T>
T Inc(int n)
{
	return 1 + n;
}

template <typename T1, typename T2, typename T3>
T1 Sum(T2 a, T3 b)
{
	return a + b;
}

// 糟糕的设计，用户必须指定所有三个模板参数，应该学习这样： template <typename T1, typename T2, typename T3> T1 Sum(T2 a, T3 b);
template <typename T1, typename T2, typename T3>
T3 TSum(T2 a, T1 b)
{
	return a + b;
}

int main()
{
	int a = 4;
	double b = 4.5;
	/*
	* 错误！模板参数不匹配。因为无法从Compare模板生成与之类型完全匹配的模板函数Compare(int,double)。
	* 虽然可以从Compare模板生成int Compare(double,double)和int Compare(int,int)，但是到底应该把a自动转换成double类型后调用前者还是应该把b自动转换成int类型后调用后者呢？
	* 这是存在二义性的，因此编译器会报错。
	*/
	// cout << Compare(a, b) << endl;
	cout << Compare<double>(a, b) << endl;			// 输出 -1
	cout << Compare<int>(a, b) << endl;			// 输出 0
	cout << Inc<double>(a) / 2 << endl;			// 输出 2.5
	cout << Inc<int>(a) / 2 << endl;			// 输出 2
	// 显式指定 T1 ，而 T2 和 T3 类型则由编译器从函数实参 a 和 b 的类型推断出来
	cout << Sum<double>(a, b) << endl;			// 输出 8.5
	cout << Sum<int>(a, b) << endl;				// 输出 8
	

	// 糟糕的设计，用户必须指定所有三个模板参数
	cout << TSum<int, double, long long>(a, b) << endl;			// 输出 8
	/* 如果这样调用将出错，因为无法推断出 T3 参数。
	cout << TSum<long long>(a, b) << endl;
	*/

	return 0;
}



// tips:
//	1. 模板调用语句可以明确指明要把参数类型实例化为哪种类型。
//	因为，在某些情况下，编译器无法推断出模板实参的类型。其他一些情况下，我们希望允许用户控制模板实例化。
//	2. 显式模板实参按由左至右的顺序与对应的模板参数匹配：第一个模板实参与第一个模板参数匹配，第二个实参与第二个参数匹配，依此类推。
//	只有尾部（最右）参数的显式模板实参才可以忽略，而且前提是它们可以从函数参数推断出来。