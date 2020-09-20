// 重载类型强制转换运算符

#include <iostream>

using namespace std;

class CComplex
{
private:
	double real;
	double imag;
public:
	CComplex(double real_ = 0.0, double imag_ = 0.0) :real(real_), imag(imag_) {}
	operator double();		// 重载强制类型转换运算符 double
};
CComplex::operator double()
{
	return real;
}

int main()
{
	CComplex a(4.3, 21.6);
	cout << (double)a << endl;		// 等价于 a.operator double();	输出 4.3
	double n = 100 + a;				// 等价于 double n = 100 + a.operator double();
	
	cout << n << endl;				// 输出 104.3
	cout << a.operator double() << endl;		// 输出 4.3
	return 0;
}



// tips: 
//   1. 在C++中，类型的名字(包括类的名字)本身也是一种运算符，即类型强制转换运算符。
//   2. 类型强制转换运算符是单目运算符，也可以被重载，但只能重载为成员函数，不能重载为全局函数。
//   3. 重载强制类型转换运算符时，不需要指定返回值类型，因为返回值类型是确定的，就是运算符本身代表的类型，示例这里就是double