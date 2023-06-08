#include <iostream>
#include <set>

using namespace std;

set<int> A;

int A_cnt, B_cnt;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> A_cnt >> B_cnt;
	for(int i = 0; i < A_cnt; i ++)
	{
		int num;
		cin >> num;
		A.insert(num);
	}
	int cnt = 0;
	for(int i = 0; i < B_cnt; i ++)
	{
		int num;
		cin >> num;
		if(A.find(num) != A.end())
			cnt ++;
	}
	cout << A_cnt + B_cnt - cnt - cnt << endl;
}