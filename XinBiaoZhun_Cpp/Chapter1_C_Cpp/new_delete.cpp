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
//   1. 释放动态分配的内存空间，需要注意的是，释放一个指针，并不会使该指针的值变为 NULL 。