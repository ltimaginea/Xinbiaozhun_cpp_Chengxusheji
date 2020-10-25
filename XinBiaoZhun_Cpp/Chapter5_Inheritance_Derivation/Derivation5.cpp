#include <iostream>
#include <string>

using namespace std;

class CBase
{

};
class CDerivide :public CBase
{

};

int main()
{
	CBase base;
	CDerivide derivide;
	base = derivide;
	CBase& ref = derivide;
	CBase* pbase = &derivide;
	CDerivide* pder = &derivide;
	pbase = pder;
	return 0;
}



// tips:
//   1. 在公有派生的情况下，有以下三条赋值兼容规则(注意是公有派生)：
//	(1) 派生类对象可以赋值给基类对象。
//	(2) 派生类对象可以用来初始化基类引用。
//	(3) 派生类对象的地址可以赋值给基类指针，亦即派生类的指针可以赋值给基类指针。
//	上面三条反过来是不成立的。例如，不能把基类对象赋值给派生类对象。
//   2. 将派生类对象赋值给基类对象时，在赋值号“=”没有被重载的情况下，所做的操作就是“浅拷贝”，即将派生类对象中的基类对象逐个字节地复制到“=”左边的基类对象中。