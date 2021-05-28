#include <iostream>
#include <map>
#include <utility>

using namespace std;

template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p)
{
	os << "(" << p.first << "," << p.second << ")";
	return os;
}

template <typename T>
void Print(T beg, T end)
{
	for (; beg != end; ++beg)
	{
		cout << *beg << " ";
	}
	cout << endl;
}

// 按关键字递减排序
using MyMap = map<int, double, greater<int>>;

int main()
{
	MyMap mp;
	mp.insert(MyMap::value_type(15, 2.7));
	pair<MyMap::iterator, bool> p = mp.insert(make_pair(15, 3.7));
	if (!p.second)
		cout << *p.first << " already exits" << endl;
	cout << mp.count(15) << endl;
	mp.insert(make_pair(20, 9.3));
	cout << mp[40] << endl;
	Print(mp.begin(), mp.end());
	mp[15] = 6.28;
	mp[17] = 3.14;
	Print(mp.begin(), mp.end());
	return 0;
}

// tips:
//	1. 如果关键字并不在map中，下标运算符[] 会为它创建一个元素并插入到map中，关联值将进行值初始化。