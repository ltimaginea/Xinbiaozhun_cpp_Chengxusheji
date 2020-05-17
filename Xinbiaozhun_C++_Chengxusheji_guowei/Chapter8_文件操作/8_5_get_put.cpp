// 8_5_get_put.cpp : 此程序实现文件复制的功能。用法是在“命令提示符”窗口输入：
//	.\a.exe 源文件名 目标文件名
//	就能将源文件复制到目标文件。例如：
//	.\a.exe .\student.dat .\clone.dat

#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "File name missing!" << endl;
		return 0;
	}
	ifstream inFile(argv[1], ios::binary | ios::in);
	if (!inFile)
	{
		cout << "open " << argv[1] << " error!" << endl;
		return 0;
	}
	ofstream outFile(argv[2], ios::binary | ios::out);
	if (!outFile)
	{
		inFile.close();
		cout << "open " << argv[2] << " error!";
		return 0;
	}
	char c;
	while (inFile.get(c))
	{
		outFile.put(c);
	}
	inFile.close();
	outFile.close();
	return 0;
}