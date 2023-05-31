#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<int, int>mp;
vector<int> vt;
vector<int> vt2;
int N, C;

int main()
{
	cin >> N >> C;
	for(int i = 0; i < N; i ++)
	{
		int tmp;
		cin >> tmp;
		int idx = -1;
		for(int j = 0; j < vt2.size(); j ++)
		{
			if(vt2[j] == tmp)
			{
				idx = j;
				break;
			}
		}
		if(idx == -1)
		{
			vt.push_back(1);
			vt2.push_back(tmp);
		}
		else
			vt[idx] ++;
	}
	for(int i = 0; i < vt.size(); i ++)
	{
		int mx = 0;
		int idx = -1;
		for(int j = 0; j < vt.size(); j ++)
		{
			if(vt[j] > mx)
			{
				mx = vt[j];
				idx = j;
			}
		}
		for(int j = 0; j < vt[idx]; j ++)
			cout << vt2[idx] << " ";
		vt[idx] = 0;
	}
	cout << endl;
}