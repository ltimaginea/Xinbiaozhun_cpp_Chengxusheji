#include <iostream>

using namespace std;

int main()
{
	int x = 100, y = 200, z = 300;
	auto ff = [=, &y, &z](int n)->int
	{
		cout << x << endl;
		++y;
		++z;
		return n * n;
	};
	cout << ff(15) << endl;
	cout << y << "," << z << endl;

	return 0;
}

// tips: 
//   1. Lambda 表达式实际上是一个匿名函数。