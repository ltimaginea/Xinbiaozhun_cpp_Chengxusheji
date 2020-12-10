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
	return 0;			// 输出 B::hello		A::bye
}



// tips:
//	1. 在构造函数和析构函数中调用虚函数不是多态。