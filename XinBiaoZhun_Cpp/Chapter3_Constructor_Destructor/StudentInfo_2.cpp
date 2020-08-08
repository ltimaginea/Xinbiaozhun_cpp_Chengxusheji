// StudentInfo_2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

class CStudent
{
private:
	char name[20];
	int age;
	int id;
	int score[4];
	double average;
private:
	void CalcuAver();
public:
	void GetScore();
	void PrintInfo();
};
void CStudent::GetScore()
{
	char buff[100];
	cin.getline(buff, 100);
	char* position = strchr(buff, ',');
	strncpy(name, buff, position - buff);
	name[position - buff] = 0;
	++position;
	sscanf(position, "%d,%d,%d,%d,%d,%d", &age, &id, &score[0], &score[1], &score[2], &score[3]);
	CalcuAver();
}
void CStudent::CalcuAver()
{
	int sum = 0;
	for (int i = 0; i < 4; i++)
	{
		sum += score[i];
	}
	average = sum / 4.0;
}
void CStudent::PrintInfo()
{
	cout << name << " " << age << " " << id << " " << average << endl;
}
int main()
{
	CStudent stu;
	stu.GetScore();
	stu.PrintInfo();
	return 0;
}

