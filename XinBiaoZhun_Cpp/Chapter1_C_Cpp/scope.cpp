#include <iostream>

int reused = 42;

int main()
{
	int unique = 0;
	std::cout << reused << " " << unique << std::endl;
	
	int  reused = 0;
	std::cout << reused << " " << unique << std::endl;

	// ���� �����������:: ��ʹ��ͬ��ȫ�ֱ��� reused
	std::cout << ::reused << " " << unique << std::endl;
	return 0;
}

