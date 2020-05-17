// 操作文件读写指针.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    class CStudent
    {
    public:
        char name[20];
        int age;
    };
    CStudent stu;
    fstream ioFile("student.txt", ios::in | ios::out);
    if (!ioFile)
    {
        cout << "open error!" << endl;
        return 0;
    }
    int L = 0, R;
    ioFile.seekg(0, ios::end);
    R = ioFile.tellg() / sizeof(CStudent) - 1;
    do
    {
        int cur = (L + R) / 2;
        ioFile.seekg(cur, ios::beg);
        ioFile.read((char*)(&stu), sizeof(stu));
        int temp = strcmp(stu.name, "Jack");
        if (temp == 0)
        {
            ioFile.seekp(cur, ios::beg);
            stu.age = 53;
            ioFile.write((char*)(&stu), sizeof(stu));
            cout << "OK!" << endl;
        }
        else if (temp > 0)
        {
            R = cur - 1;
        }
        else
        {
            L = cur + 1;
        }
    } while (L <= R);
    ioFile.close();
    return 0;
}

// 操作文件读写指针常用函数: 
//   1. seekg
//   2. seekp
//   3. tellg
//   4. tellp
