#include <iostream>
#include <set>

using namespace std;

template <typename T>
void Print(T first, T second)
{
	for (; first != second; ++first)
	{
		cout << *first << " ";
	}
	cout << endl;
}

class A
{
private:
	int n_;
public:
	A(int n) :n_(n) {}
	friend bool operator<(const A& a1, const A& a2);
	friend ostream& operator<<(ostream& os, const A& a);
	friend class MyLess;
};

bool operator<(const A& a1, const A& a2)
{
	return a1.n_ < a2.n_;
}

ostream& operator<<(ostream& os, const A& a)
{
	os << a.n_;
	return os;
}

class MyLess
{
public:
	// 按个位数比较大小
	bool operator()(const A& a1, const A& a2) const
	{
		return (a1.n_ % 10) < (a2.n_ % 10);
	}
};

typedef multiset<A> MSET1;
typedef multiset<A, MyLess> MSET2;

int main()
{
	const int kSize = 6;
	A a[kSize] = { 4,22,19,8,33,40 };
	MSET1 m1;
	m1.insert(begin(a), end(a));
	m1.insert(22);
	cout << m1.count(22) << endl;
	Print(m1.begin(), m1.end());
	MSET1::iterator pp = m1.find(19);
	if (pp != m1.end())
	{
		cout << "found" << endl;
	}
	cout << *m1.lower_bound(22) << "," << *m1.upper_bound(22) << endl;
	pp = m1.erase(m1.lower_bound(22), m1.upper_bound(22));
	Print(m1.begin(), m1.end());
	cout << *pp << endl;

	MSET2 m2;
	m2.insert(begin(a), end(a));
	Print(m2.begin(), m2.end());

	return 0;
}

// tips:
//	1. multiset 容器中的元素默认是用"<"运算符比较大小的。