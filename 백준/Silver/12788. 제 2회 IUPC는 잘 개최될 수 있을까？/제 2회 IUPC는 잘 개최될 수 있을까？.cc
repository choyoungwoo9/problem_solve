#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int M, K;
vector<int> member;

int main()
{
	cin >> N >> M >> K;
	for(int i = 0; i < N; i ++)
	{
		int num;
		cin >> num;
		member.push_back(num);
	}
	sort(member.begin(), member.end(), greater<int>());
	int sum = 0;
	for(int i = 0; i < N; i++)
	{
		sum += member[i];
		if(sum >= M * K)
		{
			cout << i+1 << endl;
			return 0;
		}
	}
	cout << "STRESS" << endl;
}