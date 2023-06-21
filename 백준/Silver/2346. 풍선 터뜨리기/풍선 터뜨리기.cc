#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int> > vt;
int N;

int main()
{
	cin >> N;
	for(int i = 0; i < N; i ++)
	{
		int num;
		cin >> num;
		vt.push_back(pair<int, int>(i, num));
	}
	int cur_idx = 0;
	for(int i = 0; i < N; i ++)
	{
		cout << vt[cur_idx].first+1 << " ";
		int cnt = vt[cur_idx].second;
		// cout << cnt << " ";
		vt.erase(vt.begin()+cur_idx);
		if(vt.size() == 0)
			break;
		if(cnt > 0)
		{
			cur_idx = (cur_idx + cnt-1)%vt.size();
		}
		else
		{
			cur_idx = (cur_idx + cnt)%(int)vt.size();
			// cout << cur_idx << " ";
			if(cur_idx < 0)
				cur_idx += vt.size();
		}
		// cout << cur_idx << endl;
	}
	cout << endl;
}