// 类型转换构造函数

#include <iostream>

using namespace std;

class CComplex
{
public:
	double real;
	double imag;
	CComplex(int real_);
	CComplex(int real_, int imag_);
};
CComplex::CComplex(int real_)
{
	cout << "IntConstructor called" << endl;
	real = real_;
	imag = 0;
}
CComplex::CComplex(int real_, int imag_)
{
	real = real_;
	imag = imag_;
}

int main()
{
	CComplex c1(12, 13);
	c1 = 100;	// 100会被自动转换成一个临时CComplex对象，该临时对象以100为实参，用CComplex(int)构造函数初始化，然后再将该临时对象的值赋给c1
	CComplex c2 = 21;		// 同上，会调用类型转换构造函数CComplex(int)
	cout << "real=" << c1.real << ",imag=" << c1.imag << endl;		// 输出 real=100,imag=0
	return 0;
}



// tips: 
//   1. 除复制构造函数外，只有一个参数的构造函数一般都可以称作类型转换构造函数，因为这样的构造函数能起到类型自动转换的作用。