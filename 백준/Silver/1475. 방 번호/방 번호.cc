#include <iostream>
#include <string>
using namespace std;
int ar[10];

string str;

int main()
{
	
	cin >> str;
	for(int i = 0; i < str.size(); i ++)
		ar[str[i]-'0'] ++;
	int gap = abs(ar[6] - ar[9]);
	if(gap % 2 == 0)
		gap = gap / 2;
	else
		gap = gap / 2 + 1;
	ar[6] = min(ar[6], ar[9]) + gap;
	ar[9] = 0;
	int ans = 0;
	for(int i = 0; i < 10; i ++)
	{
		if(ar[i] > ans)
			ans = ar[i];
	}
	cout << ans << endl;
}