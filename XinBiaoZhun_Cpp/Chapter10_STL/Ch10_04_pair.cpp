#include <iostream>
#include <string>
#include <utility>

using namespace std;

int main()
{
	pair<int, double> p1;		// 进行值初始化，输出 0 0
	cout << p1.first << " " << p1.second << endl;
	pair<string, int> p2("this", 20);
	cout << p2.first << " " << p2.second << endl;
	pair<string, string> p3{ "James","Petter" };
	cout << p3.first << " " << p3.second << endl;
	pair<int, int> p4(pair<int, int>(-100, 100));
	cout << p4.first << " " << p4.second << endl;
	pair<double, string> p5 = make_pair(11.25, "202105062204");
	cout << p5.first << " " << p5.second << endl;

	return 0;
}

// tips: 
//   1. pair的数据成员first和second是public的。