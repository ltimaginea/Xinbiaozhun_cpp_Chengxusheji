#include <iostream>
#include <fstream>
using namespace std;
class CStudent
{
public:
	char name[21];	// 字节对齐为24
	int age;
};
int main()
{
	CStudent stu;
	fstream ioFile(".\\test.dat", ios::out | ios::binary);
	if (!ioFile)
	{
		cout << "open test.dat error!" << endl;
		return 0;
	}
	while (cin >> stu.name >> stu.age)
	{
		ioFile.write((char *)(&stu), sizeof(CStudent));
	}
	ioFile.close();

	ioFile.open(".\\test.dat", ios::in | ios::binary);
	if (!ioFile)
	{
		cout << "open error!" << endl;
		return 0;
	}
	
	fstream cloneFile(".\\clone.dat", ios::out | ios::binary);
	if (!cloneFile)
	{
		ioFile.close();
		cout << "open clone.dat error!" << endl;
		return 0;
	}

	while (ioFile.read((char *)(&stu), sizeof(CStudent)))
	{
		cout << ioFile.gcount() << endl;
		cloneFile.write((char*)(&stu), sizeof(stu));
	}
	ioFile.close();
	cloneFile.close();

	/* 打印拷贝文件的内容
	cloneFile.open(".\\clone.dat", ios::in | ios::binary);
	if(!cloneFile)
	{
		cout<<"open error!"<<endl;
	}
	while (cloneFile.read((char*)(&stu), sizeof(CStudent)))
	{
		cout << stu.name << " " << stu.age << endl;
	}
	cloneFile.close();
	*/
	
	return 0;
}