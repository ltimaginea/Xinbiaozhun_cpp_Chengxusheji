# 回避虚函数的机制

在某些情况下，我们希望对虚函数的调用不要进行动态绑定，而是强迫其执行虚函数的某个特定版本。使用作用域运算符可以实现这一目的，例如下面的代码:

```c++
#include <iostream>
#include <string>

using namespace std;

class Base
{
public:
	virtual void fcn();
};

class Derive :public Base
{
public:
	virtual void fcn();
};

void Base::fcn() { cout << "Base is called" << endl; }
void Derive::fcn() { cout << "Derive is called" << endl; }

int main()
{
	Derive derive;
	Base* pBase = &derive;
	pBase->fcn();			// 输出 Derive is called
	// 强行调用基类中定义的函数版本而不管pBase的动态类型到底是什么,该调用将在编译时完成解析
	pBase->Base::fcn();		// 输出 Base is called
	return 0;
}
```



什么时候我们需要回避虚函数的默认机制呢？通常是当一个派生类的虚函数调用它覆盖的基类的虚函数版本时。在此情况下，基类的版本通常完成继承层次中所有类型都要做的共同任务，而派生类中定义的版本需要执行一些与派生类本身密切相关的操作。

通常情况下，只有成员函数（或友元）中的代码才需要使用作用域运算符来回避虚函数的机制。

如果一个派生类虚函数需要调用它的基类版本，但是没有使用作用域运算符，则在运行时该调用将被解析为对派生类版本自身的调用，从而导致无限递归。