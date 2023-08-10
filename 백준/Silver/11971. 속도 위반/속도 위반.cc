#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<pair<int, int> >road;
vector<pair<int, int> >my;
int answer = 0;

int getSpeed(int cur, vector<pair<int,int> > &info)
{
	int sum = 0;
	for(int i = 0; i < info.size(); i++)
	{
		sum += info[i].first;
		if(sum > cur)
			return info[i].second;
	}
}

int main()
{
	cin >> N >> M;
	for(int i = 0; i < N; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		road.push_back(make_pair(n1, n2));
	}
	for(int i = 0; i < M; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		my.push_back(make_pair(n1, n2));
	}
	for(int i = 0; i < 100; i++)
	{
		int roadSpeed = getSpeed(i, road);
		int mySpeed = getSpeed(i, my);
		answer = max(answer, mySpeed - roadSpeed);
	}
	cout << answer << endl;
}