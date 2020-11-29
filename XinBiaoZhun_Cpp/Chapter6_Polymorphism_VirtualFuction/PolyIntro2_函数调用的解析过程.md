# 函数调用的解析过程

理解函数调用的解析过程对于理解C++的继承至关重要，假定我们调用`p->mem()`(或者`obj.mem()`)，则依次执行以下4个步骤:

- 首先确定`p`(或`obj`)的静态类型。因为我们调用的是一个成员，所以该类型必然是类类型。

- 在`p`(或`obj`)的静态类型对应的类中查找`mem`。如果找不到，则依次在直接基类中不断查找直至到达继承链的顶端。如果找遍了该类及其基类仍然找不到，则编译器将报错。

- 一旦找到了`mem`，就进行常规的类型检查以确认对于当前找到的`mem`，本次调用是否合法。

- 假设调用合法，则编译器将根据调用的是否是虚函数而产生不同的代码：

  —— 如果`mem`是虚函数且我们是通过引用或指针进行的调用，则编译器产生的代码将在运行时确定到底运行该虚函数的哪个版本，依据是对象的动态类型。

  —— 反之，如果`mem`不是虚函数或者我们是通过对象(而非引用或指针)进行的调用，则编译器将产生一个常规函数调用。

​      

我们现在可以理解为什么基类与派生类中的虚函数必须有相同的形参列表了。**假如基类与派生类的虚函数接受的实参不同，则我们就无法通过基类的引用或指针调用派生类的虚函数了**。例如下面的程序：

```cpp
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
	// fcn(int)形参列表与基类中的fcn()不一致,是一个新的虚函数,既会隐藏基类fcn(),也会继承基类Base::fcn()的定义
	virtual void fcn(int);
};

void Base::fcn()
{
	cout << "Base is called" << endl;
}

void Derive::fcn(int i)
{
	cout << "Derive is called" << endl;
}

int main()
{
	Derive derive;
	Base* pBase = &derive;
	// 输出 Base is called
	pBase->fcn();
	return 0;
}
```

