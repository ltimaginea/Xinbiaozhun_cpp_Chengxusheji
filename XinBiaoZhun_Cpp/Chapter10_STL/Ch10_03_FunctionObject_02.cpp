#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

auto print_interval = [](auto first, auto last)->void
{
	for (auto it = first; it != last; ++it)
		cout << *it << " ";
	cout << endl;
};

class A
{
public:
	A(int v) :v_(v) {  }
	bool operator<(const A& a) const		// 声明为 const ，是保持运算符的原有特性的做法。这样const对象和非const对象都可以调用 operator<
	{
		return v_ < a.v_;
	}
	bool operator>(const A& a) const		// 声明为 const ，是保持运算符的原有特性的做法。这样const对象和非const对象都可以调用 operator>
	{
		return v_ > a.v_;
	}
	int v_;
};

bool GreaterA(const A& a1, const A& a2)
{
	return a1 > a2;			// a1 是const对象，只能调用 const成员函数 operator>
}

struct LessA
{
	bool operator()(const A& a1, const A& a2)
	{
		return (a1.v_ % 10) < (a2.v_ % 10);			// 以个位数作为判断依据
	}
};

ostream& operator<<(ostream& os, const A& a)
{
	os << a.v_;
	return os;
}

int main()
{
	array<int, 4> a1 = { 5,2,4,1 };
	array < A, 5 > a2 = { 13, 12, 9, 8, 16 };

	sort(a1.begin(), a1.end());
	print_interval(a1.begin(), a1.end());

	sort(a2.begin(), a2.end());
	print_interval(a2.begin(), a2.end());
	sort(a2.begin(), a2.end(), GreaterA);
	print_interval(a2.begin(), a2.end());
	sort(a2.begin(), a2.end(), LessA());
	print_interval(a2.begin(), a2.end());

	return 0;
}



// tips:
//	1. 常量对象，以及常量对象的引用或指针都只能调用常量成员函数。
//	2. 如果两个成员函数的名字和参数表相同，但一个是 const 的，一个不是，则它们算重载。