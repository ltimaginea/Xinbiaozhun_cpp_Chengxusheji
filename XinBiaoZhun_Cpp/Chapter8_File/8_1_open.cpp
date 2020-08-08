#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream inFile;
	// 文件名可以是绝对路径，也可以是相对路径
	inFile.open("D:\\gaoyy\\test.txt", ios::in);
	if (inFile)
	{
		inFile.close();
	}
	else
	{
		cout << "test.txt doesn't exit." << endl;
	}
	ofstream outFile;
	// 如果该文件原来就存在，则打开时清除原来的内容
	// 如果文件不存在，则新建该文件，如下行示例。如果指定的目录不存在，则打开出错，即不可以创建新目录文件夹,再在其中创建新文件，如 "..\\temp\\test1.txt"
	outFile.open("..\\..\\test1.txt", ios::out);
	if (!outFile)
	{
		cout << "open test1.txt error." << endl;
	}
	else
	{
		cout << "open test1.txt OK." << endl;
		outFile.close();
	}
	// ios::in 结合 ios::out 使用在 ofstream 类的对象上，文件刚打开时，文件原有内容保持不变
	// 如果文件不存在，则打开出错，即不存在时不会新建该文件
	outFile.open("tmp\\test2.txt", ios::in | ios::out);
	if (outFile)
	{
		outFile.close();
	}
	else
	{
		cout << "test2.txt error." << endl;
	}
	fstream ioFile;
	// ios::in | ios::out 使用对象 fstream 时：打开已存在的文件，可读可写。文件刚打开时，保持原内容不变。如果文件不存在，则打开出错
	// ios::in | ios::out | ios::trunc 使用对象 fstream 时：打开已存在的文件，可读可写。文件刚打开时，清除原内容。如果文件不存在，则新建该文件
	ioFile.open("test3.txt", ios::in | ios::out | ios::trunc);
	if (ioFile)
	{
		ioFile.close();
	}
	else
	{
		cout << "error test3.txt" << endl;
	}
	return 0;
}
