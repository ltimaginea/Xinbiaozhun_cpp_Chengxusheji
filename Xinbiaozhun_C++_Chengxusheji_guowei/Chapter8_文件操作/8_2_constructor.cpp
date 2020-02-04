#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream inFile("D:\\test1.txt", ios::in);
	if (inFile)
	{
		inFile.close();
	}
	else
	{
		cout << "test1.txt doesn't exit.\n";
	}
	ofstream outFile("..\\test2.txt", ios::out);
	if (!outFile)
	{
		cout << "test2.txt doesn't exit.\n";
	}
	else
	{
		outFile.close();
	}
	fstream ioFile("test3.txt", ios::in | ios::out);
	if (ioFile)
	{
		cout << "test3.txt exits.\n";
		ioFile.close();
	}
	else
	{
		cout << "test3.txt doesn't exit.\n";
	}
	return 0;
}
