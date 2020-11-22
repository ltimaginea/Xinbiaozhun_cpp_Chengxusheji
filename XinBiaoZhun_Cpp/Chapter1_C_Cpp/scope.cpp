#include <iostream>

int reused = 42;

int main()
{
	int unique = 0;
	std::cout << reused << " " << unique << std::endl;
	
	int  reused = 0;
	std::cout << reused << " " << unique << std::endl;

	// 借助 作用域操作符:: 来使用同名全局变量 reused
	std::cout << ::reused << " " << unique << std::endl;
	return 0;
}



// tips:
//	1. C++语言中大多数作用域都以花括号{}分隔。


