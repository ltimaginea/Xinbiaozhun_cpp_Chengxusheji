#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
int cmp(const void * a, const void * b)
{
	// 递减排序
	return *((int *)b) - *((int *)a);
}
int main()
{
	const int max_size = 1000;
	int temp[max_size] = { 0 };
	ifstream inFile("D://inTest.txt", ios::in);
	if (!inFile)
	{
		cout << "inTest.txt doesn't exit." << endl;
		return 0;
	}
	ofstream outFile("D://outTest.txt", ios::out);
	if (!outFile)
	{
		cout << "outTest.txt doesn't exit." << endl;
		// 程序结束前，不要忘记关闭以前打开过的文件
		inFile.close();
		return 0;
	}
	int num = 0;
	int x;
	// 读到文件末尾时，"inFile >> x" 就会返回 false ，循环结束
	while (inFile >> x)
	{
		temp[num++] = x;
	}

	// 但是下面这样会出错！
	// while (inFile >> temp[num++]);	因为在读取最后一个数据之后，下一次再读取时才会返回 false ，而下一次再读取时同时还会执行 num++ ，最终导致 num 值+1
	/* 可以修改为下面这样
	while (inFile >> temp[num])
	{
		num++;
	}
	*/

	inFile.close();
	qsort(temp, num, sizeof(int), cmp);
	for (int i = 0; i < num; i++)
	{
		outFile << temp[i] << " ";
	}
	outFile.close();
	return 0;
}