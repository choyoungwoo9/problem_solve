#include <iostream>
#include <vector>

using namespace std;

bool table[1000001];

void eratosthenes()
{
	for(int i = 2; i <= 1000000; i++)
	{
		if(table[i])
			continue;
		for(int j = 2; j * i <= 1000000; j++)
			table[j*i] = 1;
	}
}

int make_cur(int num)
{
	int cur = 0;
	while(num)
	{
		cur += (num % 10) * (num % 10);
		num = num / 10;
	}
	return cur;
}

//0 미사용 1 상근수 2 상근수아님
int table2[1000001];

void getsangun()
{
	for(int i = 0; i <= 1000000; i ++)
	{
		if(table2[i] != 0)
			continue;
		vector<int> vt;
		int cur = i;
		while(1){
			int flag = 0;
			for(int j = 0; j < vt.size(); j++)
			{
				if(cur == vt[j])
					flag = 2;
			}
			if(cur == 1)
				flag = 1;
			if(flag == 0)
				flag = table2[cur];
			if(flag == 0)
			{
				vt.push_back(cur);
				cur = make_cur(cur);
				continue;
			}
			else
			{
				for(int j = 0; j < vt.size(); j++)
					table2[vt[j]] = flag;
				break;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	eratosthenes();
	getsangun();
	int n;
	cin >> n;
	for(int i = 2; i <= n; i++)
		if(!table[i] && table2[i] == 1)
			cout << i << endl;
}