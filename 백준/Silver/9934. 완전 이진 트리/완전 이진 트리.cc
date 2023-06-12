#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int K;
vector<int> vt;

vector<int> answer[10];

void recursive_make(int start, int end, int depth)
{
	int mid = (start + end) / 2;
	answer[depth].push_back(vt[mid]);
	if(start == end)
	{
		return ;
	}
	recursive_make(start, mid-1, depth+1);
	recursive_make(mid+1, end, depth+1);
}

int main()
{
	cin >> K;
	for(int i = 0; i < pow(2, K)-1; i ++)
	{
		int num;
		cin >> num;
		vt.push_back(num);
	}
	recursive_make(0, vt.size()-1, 0);
	for(int i = 0; i < K; i ++)
	{
		for(int j = 0; j < answer[i].size(); j ++)
			cout << answer[i][j] << " ";
		cout << endl;
	}
}