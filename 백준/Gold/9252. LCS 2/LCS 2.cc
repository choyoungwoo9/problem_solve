#include <iostream>
#include <string>

using namespace std;

string a, b;

typedef struct tmp
{
	int count;
	int flag;
}tmp;
tmp ar[1001][1001];

int m_max(int a, int b)
{
	if(a > b)
		return a;
	return b;
}

void lcs()
{
	for(int i = 1; i <= a.size(); i ++)
	{
		for(int j = 1; j <= b.size(); j++)
		{
			if(a[i-1] == b[j-1])
			{
				ar[i][j].count = ar[i-1][j-1].count + 1;
				ar[i][j].flag = 1;
			}
			else
			{
				ar[i][j].count = m_max(ar[i-1][j].count, ar[i][j-1].count);
				ar[i][j].flag = 0;
			}
		}
	}
}

string answer;

void make_answer()
{
	int i = a.size();
	int j = b.size();
	while(1)
	{
		if(i == 0 || j == 0)
			return ;
		if(ar[i][j].flag == 1)
		{
			answer = a[i-1] + answer;
			i = i - 1;
			j = j - 1;
		}
		else
		{
			if(ar[i-1][j].count > ar[i][j-1].count)
			{
				i = i -1;
			}
			else
			{
				j = j -1;
			}
		}
	}
}

int main()
{
	cin >> a >> b;
	lcs();
	make_answer();
	cout << ar[a.size()][b.size()].count << endl;
	if(!ar[a.size()][b.size()].count)
		return 0;
	cout << answer << endl;
}