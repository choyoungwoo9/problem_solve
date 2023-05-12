#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class member
{
	public:
		member(int p1, int p2, string p3)
		{
			age = p1;
			order = p2;
			name = p3;
		}
		int age;
		int order;
		std::string name;
};

struct compare
{
	bool operator()(member &a, member &b)
	{
		if(a.age == b.age)
		{
			return a.order > b.order;
		}
		return a.age > b.age;
	}
};

priority_queue<member, vector<member>, compare> que;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	for(int i = 0; i < N; i ++)
	{
		int age;
		string name;
		cin >> age >> name;
		que.push(member(age, i, name));
	}

	for(int i = 0; i < N; i ++)
	{
		cout << que.top().age << " " << que.top().name << "\n";
		que.pop();
	}
}