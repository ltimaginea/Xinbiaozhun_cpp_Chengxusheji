// 重载自增、自减运算符

#include <iostream>

using namespace std;

class CDemo
{
private:
	int n;
public:
	CDemo(int i = 0) :n(i) {}
	CDemo& operator++();					// 用于前置形式
	CDemo operator++(int);					// 用于后置形式
	operator int();
	friend CDemo& operator--(CDemo&);		// 用于前置形式
	friend CDemo operator--(CDemo&, int);	// 用于后置形式
};
CDemo& CDemo::operator++()
{
	n++;
	return *this;
}
CDemo CDemo::operator++(int i)
{
	CDemo tmp(*this);
	n++;
	return tmp;
}
CDemo::operator int()
{
	return n;
}
CDemo& operator--(CDemo& d)
{
	d.n--;
	return d;
}
CDemo operator--(CDemo& d, int i)
{
	CDemo tmp(d);
	d.n--;
	return tmp;
}
int main()
{
	CDemo d(5);
	cout << d++ << ",";			// 等价于 d.operator++(0)
	cout << d << ",";	// 等价于 d.operator int()
	cout << ++d << ",";			// 等价于 d.operator++()
	cout << d << ",";
	cout << d-- << ",";			// 等价于 operator--(d, 0)
	cout << d << ",";
	cout << --d << ",";			// 等价于 operator--(d)
	cout << d << endl;
	return 0;					// 程序输出	5,6,7,7,7,6,5,5
}



// tips: 
//   1. C++规定，在重载"++"或"--"时，允许写一个增加了无用int类型的形参版本，用以区分前置、后置。
//	(1)在处理"++"或"--"的前置表达式时，调用参数个数正常的重载函数。
//	(2)在处理"++"或"--"时后置表达式时，调用多出一个参数的重载函数。
//   2. 调用后置形式的重载函数时，对于那个没用的int类型形参，编译器自动以0作为实参。
//   3. 前置"++"运算符的返回值类型是CDemo&，而后置"++"运算符的返回值类型是CDemo，这是让运算符重载保持原运算符的用法。"--"同理。
//   4. 示例程序中，将"--"运算符重载为全局函数，其实重载为成员函数更好，示例仅仅是演示"--"可以重载为全局函数而已。