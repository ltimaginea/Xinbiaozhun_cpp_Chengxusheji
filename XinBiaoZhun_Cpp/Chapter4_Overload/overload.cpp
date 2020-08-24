#include <iostream>

using namespace std;

int Max(int a, int b)
{
	cout << "Max 1" << endl;
	return (a > b ? a : b);
}
// int Max(int a, int b, int c = 0);		// eg: Max(3,4);	会引发二义性错误
double Max(double a, double b)
{
	cout << "Max 2" << endl;
	return (a > b ? a : b);
}
double Max(double a, double b, double c)
{
	cout << "Max 3" << endl;
	return ((a > b) ? (a > c ? a : c) : (b > c ? b : c));
}

int main()
{
	Max(3, 4);				// 调用 int Max(int,int)
	Max(2.4, 6.1);			// 调用 double Max(double,double)
	Max(1.2, 3.4, 5);		// 调用 double Max(double,double,double)
	Max(1, 2, 3);			// 调用 double Max(double,double,double)
	// Max(3, 1.5);			// 编译出错：二义性
	return 0;
}



// tips: 
//   1. 函数重载，编译器是根据函数调用语句中的实参的个数和类型来判断应该调用哪个函数。
//   2. 同名函数只有参数表不同才算重载。两个同名函数的参数表相同而返回值类型不同不是重载，而是重复定义，是不允许的。