#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int ar[27];

int main()
{
	string str;
	cin >> str;
	for(auto iter = str.begin(); iter != str.end(); iter ++)
		*iter >= 'a' ? ar[*iter - 'a'] ++ : ar[*iter - 'A'] ++;
	int maxValue = 0;
	for(int i = 0; i < 27; i ++)
		maxValue = max(maxValue, ar[i]);
	int idx = 0;
	int cnt = 0;
	for(int i = 0; i < 27; i ++)
		if(maxValue == ar[i])
		{
			cnt ++;
			idx = i;
		}
	if(cnt > 1)
		cout << '?' << endl;
	else
		cout << (char) (idx + 'A') << endl;
}
