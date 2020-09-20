// 运算符重载为友元函数

#include <iostream>

using namespace std;

class CComplex
{
private:
	double real;
	double imag;
public:
	CComplex(double real_ = 0.0, double imag_ = 0.0) :real(real_), imag(imag_) {}
	CComplex operator+(double r);
	friend CComplex operator+(double r, const CComplex& a);		// 友元运算符函数，来处理5+a的情况
};
CComplex CComplex::operator+(double r)			// 处理 a+5
{
	return CComplex(real + r, imag);
}
CComplex operator+(double r, const CComplex& a)		// 处理 5+a
{
	return CComplex(r + a.real, r + a.imag);
}

int main()
{
	CComplex a(4, 4), b;
	b = a + 5;
	b = 5 + a;
	return 0;
}



// tips: 
//   1. 有时将运算符重载为类的成员函数不能满足需求，重载为全局函数又不能访问类的私有成员，这时可以将运算符重载为友元。