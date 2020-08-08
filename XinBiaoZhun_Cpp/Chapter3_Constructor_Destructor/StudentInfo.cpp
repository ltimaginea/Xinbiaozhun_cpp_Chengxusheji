// StudentInfo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;

class CStudent
{
private:
	string name;
	int age;
	int id;
	int score[4];
	double average;
private:
	void CalAverage();
public:
	void GetScore();
	void PrintInfo();
};
void CStudent::GetScore()
{
	cin >> name >> age >> id;
	for (int i = 0; i < 4; i++)
	{
		cin >> score[i];
	}
	CalAverage();
}
void CStudent::CalAverage()
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
