// inline

#include <iostream>

using namespace std;

inline int Max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int main()
{
	cout << Max(23, 5) << endl;
	return 0;
}