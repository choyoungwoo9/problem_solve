#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> vt;

bool compare(const string &a, const string &b)
{
	if(a.size() == b.size())
	{
		return a < b;
	}
	else
	{
		return a.size() < b.size();
	}
}

int main()
{
	int N;
	cin >> N;
	for(int k = 0; k < N; k ++)
	{
		string input;
		cin >> input;

		string str;
		for(int i = 0; i < input.size(); i ++)
		{
			if(input[i] >= '0' && input[i] <= '9')
			{
				str += input[i];
			}
			else
			{
				if(str.empty())
					continue;
				else
				{
					while(1)
					{
						if(str.size() != 1 && str[0] == '0')
						{
							str = str.substr(1);
						}
						else
							break;
					}
					vt.push_back(str);
					str = "";
				}
			}
		}
		if(!str.empty())
		{
			while(1)
			{
				if(str.size() != 1 && str[0] == '0')
				{
					str = str.substr(1);
				}
				else
					break;
			}
			vt.push_back(str);
		}
	}

	sort(vt.begin(), vt.end(), compare);
	for(string s : vt)
	{
		cout << s << "\n";
	}
}
