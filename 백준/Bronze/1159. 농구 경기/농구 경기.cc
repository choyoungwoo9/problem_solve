#include <iostream>

using namespace std;

int ar[26];

int main()
{
	int N;
	cin >> N;
	for(int i = 0; i < N; i ++)
	{
		string str;
		cin >> str;
		ar[str[0] - 'a'] ++;
	}
	int flag = 1;
	for(int i = 0; i < 26; i ++)
	{
		if(ar[i] >= 5)
		{
			cout << (char)('a' + i);
			flag = 0;
		}
	}
	if(flag)
		cout << "PREDAJA";
	cout << endl;
}