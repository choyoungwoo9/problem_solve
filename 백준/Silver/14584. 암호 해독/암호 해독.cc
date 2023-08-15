#include <iostream>
#include <string>
#include <vector>

using namespace std;

string str;
vector<string> vt;

int main()
{
	cin >> str;
	int N;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		vt.push_back(s);
	}

	for(int i = 0; i < 26; i++)
	{
		for(int j = 0; j < str.size(); j++)
		{
			str[j] ++;
			if(str[j] > 'z')
				str[j] = 'a';
		}
		for(int j = 0; j < vt.size(); j++)
		{
			if(str.find(vt[j]) != string::npos)
			{
				cout << str << endl;
				return 0;
			}
		}
	}
}