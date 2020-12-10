#include <iostream>

using namespace std;

class A
{
public:
	virtual void hello() { cout << "A::hello" << endl; }
	virtual void bye() { cout << "A::bye" << endl; }
};

class B :public A
{
public:
	virtual void hello() { cout << "B::hello" << endl; }
	B() { hello(); }
	~B() { bye(); }
};

class C :public B
{
public:
	virtual void hello() { cout << "C::hello" << endl; }
};

int main()
{
	C obj;
	return 0;			// 输出	B::hello		A::bye
}



// tips:
//	1. 在构造函数和析构函数中调用虚函数不是多态。因为在编译时即可确定调用的是哪个函数。
//	如果本类有该函数，调用的就是本类的函数。如果本类没有，调用的就是直接基类的函数。如果直接基类没有，调用的就是间接基类的函数，以此类推。