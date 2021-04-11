#include <iostream>
#include <array>
#include <numeric>

using namespace std;

template <typename T>
void PrintInterval(T first, T last)
{
	for (; first != last; ++first)
	{
		cout << *first << " ";
	}
	cout << endl;
}

int SumSquares(int total, int value)
{
	return total + value * value;
}

template <typename T>
class SumPowers
{
private:
	int power_;
public:
	SumPowers(int power) :power_(power) {  }
	const T operator()(const T& total, const T& value)
	{
		T v = value;
		for (int i = 0; i < power_ - 1; ++i)
		{
			v = v * value;
		}
		return total + v;
	}
};

int main()
{
	const int kSize = 10;
	array<int, kSize> a = { 1,2,3,4,5,6,7,8,9,10 };
	array<double, kSize> d = { 1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.17 };
	PrintInterval(a.begin(), a.end());
	PrintInterval(d.begin(), d.end());
	auto result1 = accumulate(a.begin(), a.end(), 0, SumSquares);				// 函数指针
	cout << result1 << endl;
	auto result2 = accumulate(a.begin(), a.end(), 0, SumPowers<int>(3));		// 会生成一个模板类的临时对象
	cout << result2 << endl;
	auto result3 = accumulate(d.begin(), d.end(), static_cast<double>(0), SumPowers<double>(4));
	cout << result3 << endl;

	return 0;
}
