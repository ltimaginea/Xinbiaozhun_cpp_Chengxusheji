#include <iostream>
#include <string>

using namespace std;

class CBase
{
public:
	CBase() {}
	CBase(const CBase& b)
	{
		cout << "CBase::copy constructor is called." << endl;
	}
	CBase& operator=(const CBase& b)
	{
		cout << "CBase::operator= is called." << endl;
		return *this;
	}
};
class CDerivide :public CBase {};

int main()
{
	CDerivide d1, d2;
	CDerivide d3(d2);		// 会调用CBase::CBase(const CBase& b)，输出 CBase::copy constructor is called.
	d1 = d2;			// 会调用CBase::operator=(const CBase& b)，输出 CBase::operator= is called.
	return 0;
}



// tips:
//   1. 和封闭类的情况类似，如果一个派生类是用默认复制构造函数初始化的，那么它内部包含的基类对象也要用基类的复制构造函数初始化。
//   2. 如果基类重载了赋值运算符“=”而派生类没有，那么在派生类对象之间赋值，或用派生类对象对基类对象进行赋值时，其中基类部分的赋值操作是调用被基类重载的“=”完成的。
//   3. 运算符函数 operator= 不会被继承。