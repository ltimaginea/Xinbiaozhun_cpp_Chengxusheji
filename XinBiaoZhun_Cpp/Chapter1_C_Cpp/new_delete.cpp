// 动态内存分配

#include <iostream>

using namespace std;

int main()
{
	int* p;
	p = new int;
	*p = 5;

	int* pn;
	pn = new int[100];
	pn[0] = 21;

	delete p;
	delete[] pn;
	return 0;
}



// tips: 
//   1. 在 C++ 中，动态内存的管理是通过一对运算符来完成的：
//      new ，在动态内存中为对象分配空间并返回一个指向该对象的指针，我们可以选择对对象进行初始化；
//      delete ，接受一个动态对象的指针，销毁该对象，并释放与之关联的内存。释放后，该指针不再是指向动态分配的内存空间的指针了。
//   2. 释放动态分配的内存空间，需要注意的是，释放一个指针，并不会使该指针的值变为 NULL 。