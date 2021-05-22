#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;

struct Student
{
	Student(string name = "", int id = 0, int score = 0) :name_(name), id_(id), score_(score) {}

	string name_;
	int id_;
	int score_;
};

/*
* 函数第一个参数一定要传引用不能传值，否则运行时下面这行 "if (it != stu.begin())" 会报错: map iterators incompatible(不匹配)
* 因为传值就是拷贝，复制品stu.begin()产生的迭代器与原先容器stu.begin()产生的迭代器是不同的，所以用复制品stu.begin()与原先容器的迭代器比较时，结果会出现incompatible错误。
*/
void QueryStudentInfo(multimap<int, Student>& stu, multimap<int, Student>::iterator it)
{
	if (it != stu.begin())
	{
		--it;
		size_t cnt = stu.count(it->first);
		it = stu.find(it->first);
		if (cnt > 1)
		{
			for (multimap<int, Student>::iterator tmp = it; cnt > 0; --cnt)
			{
				if (tmp->second.id_ > it->second.id_)
				{
					it = tmp;
				}
				++tmp;
			}
			cout << it->second.name_ << " " << it->second.id_ << " " << it->second.score_ << endl;
		}
		else
		{
			cout << it->second.name_ << " " << it->second.id_ << " " << it->second.score_ << endl;
		}
	}
	else
	{
		cout << "Nobody" << endl;
	}
}

int main()
{
	string work_type;
	string name;
	int id = 0;
	int score = 0;
	multimap<int, Student> stu;
	while (cin >> work_type)
	{
		if (work_type == "Add")
		{
			cin >> name >> id >> score;
			stu.insert(make_pair(score, Student(name, id, score)));
		}
		else if (work_type == "Query")
		{
			cin >> score;
			multimap<int, Student>::iterator it = stu.lower_bound(score);
			QueryStudentInfo(stu, it);
		}
	}
	return 0;
}

// tips:
//	1. multimap 允许多个元素的关键字相同。