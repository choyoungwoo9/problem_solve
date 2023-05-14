#include <iostream>
#include <string>

using namespace std;

int ar[1001][1001];

string a;
string b;

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
				ar[i][j] = ar[i-1][j-1] + 1;
			}
			else
			{
				ar[i][j] = m_max(ar[i-1][j], ar[i][j-1]);
			}
		}
	}
}

int main()
{
	cin >> a >> b;
	lcs();
	cout << ar[a.size()][b.size()] << endl;
}