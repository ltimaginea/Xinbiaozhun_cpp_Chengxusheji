#include <iostream>
#include <unordered_map>
#include <string>
#include <utility>

using namespace std;

int main()
{
	unordered_map<string, int> turing_winner;
	turing_winner.insert(make_pair("Dijkstra", 1972));
	turing_winner.insert(make_pair("Scott", 1976));
	turing_winner.insert(make_pair("Wilkes", 1967));
	turing_winner.insert(make_pair("Hamming", 1968));
	turing_winner["Ritchie"] = 1983;
	
	/* Output:
	Dijkstra, 1972
	Wilkes, 1967
	Scott, 1976
	Hamming, 1968
	Ritchie, 1983*/
	for (const auto& i : turing_winner)
	{
		cout << i.first << "," << i.second << endl;
	}

	string name;
	cin >> name;
	unordered_map<string, int>::iterator p = turing_winner.find(name);
	if (p != turing_winner.end())
	{
		cout << p->second;
	}
	else
	{
		cout << "Not Found" << endl;
	}

	return 0;
}

// tips:
//	1. 无序容器的实现是哈希表。