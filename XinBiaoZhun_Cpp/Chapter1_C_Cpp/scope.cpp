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

