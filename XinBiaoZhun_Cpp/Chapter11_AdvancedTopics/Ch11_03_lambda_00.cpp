#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int a[4] = { 2,11,33,4 };
	sort(begin(a), end(a), [](int i, int j)->bool { return i % 10 > j % 10; });		// 数组a按个位数递减排序
	for_each(begin(a), end(a), [](int i) { cout << i << " "; });
	cout << endl;
	int total = 0;
	for_each(begin(a), end(a), [&](int& i)->void { total += i; i *= 2; });
	cout << total << endl;
	for_each(begin(a), end(a), [](int i) { cout << i << " "; });
	cout << endl;

	return 0;
}

// tips: 
//   1. Lambda 表达式实际上是一个匿名函数。