// 求数组中最大元素的函数模板

#include <iostream>

using namespace std;

template <typename T>
T MaxElement(T a[], int size)
{
	T tmp = a[0];
	for (int i = 0; i < size; i++)
	{
		if (tmp < a[i])
			tmp = a[i];
	}
	return tmp;
}

class CFraction
{
private:
	int numerator;
	int denominator;
public:
	CFraction(int n, int d) :numerator(n), denominator(d) {}
	bool operator<(const CFraction& f) const
	{
		if (denominator * f.denominator > 0)
			return numerator * f.denominator < denominator * f.numerator;
		else
			return numerator * f.denominator > denominator * f.numerator;
	}
	bool operator==(const CFraction& f) const
	{
		return numerator * f.denominator == denominator * f.numerator;
	}

	friend ostream& operator<<(ostream& os, const CFraction& f);
};

ostream& operator<<(ostream& os, const CFraction& f)
{
	os << f.numerator << "/" << f.denominator;
	return os;
}

int main()
{
	int a[5] = { 1,3,15,7,9 };
	CFraction f[4] = { CFraction(8,6),CFraction(-8,4), CFraction(3,2), CFraction(5,6) };
	cout << MaxElement(a, 5) << endl;
	cout << MaxElement(f, 4) << endl;
	return 0;
}



// tips:
//	1. 从示例中可以看出，在函数模板中，类型参数不但可以用来定义参数的类型，还能用于定义局部变量和函数模板的返回值。