#include <iostream>
#include <string>
#include <queue>
using namespace std;

class st
{
	public:
		string name;
		int gs;
		int ys;
		int ss;
		bool operator <(const st &param) const
		{
			if(param.gs != gs)
				return param.gs > gs;
			if(param.ys != ys)
				return param.ys < ys;
			if(param.ss != ss)
				return param.ss > ss;
			return param.name < name;
		}
};

priority_queue<st> pq;

int main()
{
	int N;
	cin >> N;
	for(int i = 0; i < N; i ++)
	{
		string str;
		int n1, n2, n3;
		cin >> str >> n1 >> n2 >> n3;
		st a;
		a.name = str;
		a.gs = n1;
		a.ys = n2;
		a.ss = n3;
		pq.push(a);
	}
	for(int i = 0; i < N; i ++)
	{
		cout << pq.top().name << "\n";
		pq.pop();
	}
}