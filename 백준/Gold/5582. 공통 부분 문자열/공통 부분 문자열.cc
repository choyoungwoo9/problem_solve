#include <iostream>
#include <string>

using namespace std;

string a;
string b;

int ar[4001][4001];

int answer = 0;

void lcs()
{
	for(int i = 1; i <= a.size(); i ++)
	{
		for(int j = 1; j <= b.size(); j ++)
		{
			if(a[i-1] == b[j-1])
			{
				ar[i][j] = ar[i-1][j-1] + 1;
				if(ar[i][j] > answer)
					answer = ar[i][j];
			}
		}
	}
}

int main()
{
	cin >> a >> b;
	lcs();
	cout << answer << endl;
}