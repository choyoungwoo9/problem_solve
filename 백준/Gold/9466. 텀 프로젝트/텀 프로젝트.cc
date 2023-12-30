#include <iostream>
#include <vector>

using namespace std;

int visited[100000];
vector<int> vt[100000];
int n;

int recursiveTrip(int startIdx, int curIdx, int cnt)
{
	if(startIdx == curIdx)
		return cnt;
	if(visited[curIdx])
		return 0;
	visited[curIdx] = 1;
	int ret = 0;
	for(int i = 0; i < vt[curIdx].size(); i ++)
		ret += recursiveTrip(startIdx, vt[curIdx][i], cnt+1);
	return ret;
}

int startTrip(int startIdx)
{
	if(visited[startIdx])
		return 0;
	visited[startIdx] = 1;
	int cnt = 0;
	for(int i = 0; i < vt[startIdx].size(); i ++)
		cnt += recursiveTrip(startIdx, vt[startIdx][i], 1);
	return cnt;
}

void init()
{
	for(int i = 0; i < n; i ++)
	{
		visited[i] = 0;
		vt[i].clear();
	}
}

void solution()
{
	cin >> n;
	init();
	for(int i = 0; i < n; i ++)
	{
		//i번째 노드가 가리키는 노드가 num
		int num;
		cin >> num;
		num --;
		//나를 가리키는 노드 저장
		vt[num].push_back(i);
	}
	int haveTeamMemberCnt = 0;
	for(int i = 0; i < n; i++)
		haveTeamMemberCnt += startTrip(i);
	// cout << haveTeamMemberCnt << endl;
	cout << n - haveTeamMemberCnt << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
	int T;
	cin >> T;
	for(int i = 0; i < T; i ++)
		solution();
}