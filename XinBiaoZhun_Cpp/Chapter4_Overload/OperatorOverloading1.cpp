// 运算符重载 + - * /

#include <iostream>

using namespace std;

class CComplex
{
public:
	double real;
	double imag;
	CComplex(double real_ = 0.0, double imag_ = 0.0) :real(real_), imag(imag_) {}
	CComplex operator-(const CComplex& c);
};
CComplex CComplex::operator-(const CComplex& c)				// 将 "-" 重载为成员函数
{
	return CComplex(real - c.real, imag - c.imag);			// 返回一个临时对象
}
CComplex operator+(const CComplex& a, const CComplex& b)		// 将 "+" 重载为全局函数
{
	return CComplex(a.real + b.real, a.imag + b.imag);		// 返回一个临时对象
}

int main()
{
	CComplex a(4, 4), b(1, 1), c;
	c = a + b;		// 等价于 c = operator+(a, b);
	cout << "real=" << c.real << ",imag=" << c.imag << endl;	// real=5,imag=5
	c = a - b;		// 等价于 c = a.operator-(b);
	cout << "real=" << c.real << ",imag=" << c.imag << endl;	// real=3,imag=3

	c = operator+(a, b);
	cout << "real=" << c.real << ",imag=" << c.imag << endl;	// real=5,imag=5
	c = a.operator-(b);
	cout << "real=" << c.real << ",imag=" << c.imag << endl;	// real=3,imag=3
	return 0;
}



// tips: 
//   1. 运算符重载的目的是使得C++中的运算符也能够用来操作对象。
//   2. 运算符重载的实质是将运算符重载为一个函数，使用运算符的表达式就被解释为对“运算符函数”的调用。
//   3. 运算符可以被重载为全局函数，也可以被重载为成员函数。一般来说，倾向于将运算符重载为成员函数，这样能够较好地体现运算符和类的关系。
//	(1)运算符被重载为全局函数时，函数参数的个数就是运算符的操作数个数，运算符的操作数就成为函数的实参。
//	(2)运算符被重载为成员函数时，函数参数的个数就是运算符的操作数个数减一，运算符的操作数有一个成为函数作用的对象，其余的成为函数的实参。
