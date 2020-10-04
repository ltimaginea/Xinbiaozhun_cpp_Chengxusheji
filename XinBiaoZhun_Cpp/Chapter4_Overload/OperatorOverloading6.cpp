// 重载 流插入运算符和流提取运算符

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class CComplex
{
private:
	double real;
	double imag;
public:
	CComplex(double real_ = 0, double imag_ = 0) :real(real_), imag(imag_) {}
	friend ostream& operator<<(ostream& os, const CComplex& c);
	friend istream& operator>>(istream& is, CComplex& c);
};
ostream& operator<<(ostream& os, const CComplex& c)
{
	os << c.real << "+" << c.imag << "i";
	return os;
}
istream& operator>>(istream& is, CComplex& c)
{
	string str;
	is >> str;
	int pos = str.find("+", 0);
	string tmp = str.substr(0, pos);
	c.real = atof(tmp.c_str());
	tmp = str.substr(pos + 1, str.length() - pos - 2);
	c.imag = atof(tmp.c_str());
	return is;
}

int main()
{
	CComplex c;
	int n;
	cin >> c >> n;
	cout << c << "," << n << endl;
	return 0;
}



// tips: 
//   1. cout是ostream类的对象。ostream类和cout都是在头文件iostream中声明的。ostream类将"<<"重载为成员函数，而且重载了多次，其中实现了“输出”功能。cin同理。
//   2. 因为没有办法修改ostream类和istream类，所以只能将"<<"和">>"重载为全局函数的形式。
//   3. operator<< 函数的参数 os 只能是ostream的引用，而不能是ostream对象，因为ostream的复制构造函数是私有的，没有办法生成ostream参数对象。operator>> 同理。
//   4. operator<< 函数的返回值类型设为 ostream& ，也是为了实现"<<"的连续使用，是保持运算符的原有特性的做法。operator>> 同理。