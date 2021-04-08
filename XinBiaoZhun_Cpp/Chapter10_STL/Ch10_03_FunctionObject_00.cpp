#include <iostream>

using namespace std;

class Average
{
public:
	double operator()(int a1, int a2, int a3)
	{
		return (double)(a1 + a2 + a3) / 3;
	}
};

int main()
{
	Average average;
	cout << average(3, 2, 3) << endl;			// 等价于 average.operator()(3, 2, 3)
	cout << average.operator()(3, 2, 3) << endl;
	cout << Average()(1, 2, 3) << endl;			// 生成一个临时匿名函数对象
	return 0;
}
