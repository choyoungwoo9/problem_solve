#include <string>
#include <iostream>
using namespace std;

int ar[26];
string str;

int main()
{
	cin >> str;
	for(int i = 0; i < str.size(); i ++)
	{
		ar[str[i]-'a'] ++;
	}
	for(int i = 0; i < 26; i ++)
		cout << ar[i] << " ";
	cout << "\n";
}