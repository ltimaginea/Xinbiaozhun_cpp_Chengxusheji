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
	bool operator<(const A& a)
	{
		return v_ < a.v_;
	}
	int v_;
};

bool GreaterA(const A& a1, const A& a2)
{
	return a1.v_ > a2.v_;
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