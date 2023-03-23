#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct team
{
	string edu;
	string name;
	int s, p;
};

struct compare
{
	bool operator()(team &A, team &B)
	{
		if(A.s == B.s)
			return A.p > B.p;
		else
			return A.s < B.s;
	}
};

priority_queue <team, vector<team>, compare>pq;


int N, K;

team team_ar[100000];

vector<string> name_ar;

int main()
{
	cin >> N >> K;
	
	for(int i = 0; i < N; i ++)
	{
		cin >> team_ar[i].edu >> team_ar[i].name >> team_ar[i].s >> team_ar[i].p;
		pq.push(team_ar[i]);
	}
	int i = 0;
	while(i < K)
	{
		int j = 0;
		for(; j < name_ar.size(); j++)
		{
			if(name_ar[j] == pq.top().edu)
				break;
		}
		if(j == name_ar.size())
		{
			name_ar.push_back(pq.top().edu);
			cout << pq.top().name << endl;
			i ++;
		}
		pq.pop();
	}
}
