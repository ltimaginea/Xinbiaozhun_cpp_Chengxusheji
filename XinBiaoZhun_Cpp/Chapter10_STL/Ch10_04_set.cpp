#include <iostream>
#include <set>

using namespace std;

int main()
{
	typedef set<int>::iterator IT;
	int a[5] = { 3,4,6,1,2 };
	set<int> st(begin(a), end(a));
	pair<IT, bool> result;
	result = st.insert(5);
	if (result.second)
	{
		cout << *result.first << " inserted" << endl;
	}
	if (st.insert(5).second)
	{
		cout << *result.first << endl;
	}
	else
	{
		cout << *result.first << " already exists" << endl;
	}

	pair<IT, IT> bounds = st.equal_range(4);
	cout << *bounds.first << "," << *bounds.second << endl;

	return 0;
}

// tips:
//	1. set 容器中不能有重复的元素。