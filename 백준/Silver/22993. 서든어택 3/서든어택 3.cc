#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
unsigned long long J;

vector<unsigned long long> players;

int main()
{
	cin >> N;
	cin >> J;
	for(int i = 1; i < N; i++)
	{
		long long num;
		cin >> num;
		players.push_back(num);
	}
	sort(players.begin(), players.end());
	for(auto it = players.begin(); it != players.end(); it++)
	{
		if(*it >= J)
		{
			cout << "No" << endl;
			return 0;
		}
		J += *it;
	}
	cout << "Yes" << endl;
}