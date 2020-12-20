#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename It>
auto fcn(It beg, It end) -> decltype(*beg)
{
	typedef decltype(*beg) begType;
	begType tmp = *beg;			// 或 decltype(*beg) tmp = *beg;
	return tmp;
}

int main()
{
	vector<int> vi = { 1,2,3,4,5 };
	vector<string> ca = { "hi","bye" };
	auto& i = fcn(vi.begin(), vi.end());
	cout << i << endl;
	decltype(fcn(ca.begin(), ca.end())) s = fcn(ca.begin(), ca.end());		// 或 auto& s = fcn(ca.begin(), ca.end());
	cout << s << endl;
	return 0;
}



// tips:
//	1. 尾置返回类型，可以解决显式指定模板实参时给使用带来的麻烦。