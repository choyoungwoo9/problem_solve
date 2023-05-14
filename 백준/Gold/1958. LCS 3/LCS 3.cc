#include <iostream>
#include <string>
using namespace std;

int ar[101][101][101];

string a, b, c;

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
			for(int k = 1; k <= c.size(); k++)
			{
				if(a[i-1] == b[j-1] && b[j-1] == c[k-1])
				{
					ar[i][j][k] = ar[i-1][j-1][k-1] + 1;
				}
				else
				{
					ar[i][j][k] = m_max(ar[i][j][k-1], m_max(ar[i][j-1][k], ar[i-1][j][k]));
				}
			}
		}
	}
}

int main()
{
	cin >> a >> b >> c;
	lcs();
	cout << ar[a.size()][b.size()][c.size()] << endl;
}