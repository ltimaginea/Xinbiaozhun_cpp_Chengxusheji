// 封闭类的复制构造函数

#include <iostream>

using namespace std;

class A
{
public:
	A()
	{
		cout << "default" << endl;
	}
	A(const A&)
	{
		cout << "copy" << endl;
	}
};
class B
{
private:
	A a;
};

int main()
{
	B b1, b2(b1);			// 程序先后输出：default  copy
	return 0;
}


// tips: 
//   1. 封闭类的对象，如果是用默认复制构造函数初始化的，那么它包含的成员对象也会用复制构造函数初始化。