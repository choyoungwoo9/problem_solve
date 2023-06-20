#include <iostream>
#include <vector>

using namespace std;

string str;
string bomb;
vector<char> vt;

int main()
{
	cin >> str;
	cin >> bomb;
	for(int i = 0; i < str.size(); i ++)
	{
		vt.push_back(str[i]);
		if(vt.size() < bomb.size())
			continue;
		int flag = 0;
		for(int j = 0; j < bomb.size(); j++)
		{
			if(bomb[j] != vt[vt.size()-bomb.size()+j])
			{
				flag = 1;
				break;
			}

		}
		if(flag==0)
		{
			for(int j = 0; j < bomb.size(); j ++)
				vt.pop_back();
		}
	}
	if(vt.empty())
		cout << "FRULA";
	else{
		for(int i = 0; i < vt.size(); i ++)
			cout << vt[i];
	}
	cout << endl;
}