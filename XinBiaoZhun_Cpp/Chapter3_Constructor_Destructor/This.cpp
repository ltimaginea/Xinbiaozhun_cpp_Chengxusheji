// this 指针

#include <iostream>

using namespace std;

class CComplex
{
public:
	double real;
	double imag;
	CComplex(double real_, double imag_) :real(real_), imag(imag_) {}
	CComplex AddOne();
};
CComplex CComplex::AddOne()
{
	++this->real;		// 等效于 ++real
	return *this;
}

int main()
{
	CComplex a(10, 5);
	CComplex b = a.AddOne();
	cout << "real=" << b.real << ",imag=" << b.imag << endl;	// 输出 real=11,imag=5
	return 0;
}

// tips: 
//   1. this 指针， this 代表指向成员函数所作用对象的指针， *this 即代表成员函数所作用的对象。
//   2. 因为静态成员函数并作用于某个对象，所以在其内部不能使用 this 指针。
//   3. 成员函数实际上的参数个数比表面上看到的多一个，多出来的参数就是 this 指针。