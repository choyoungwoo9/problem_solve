#include <iostream>
#include <string>

using namespace std;

string str;
int aSize = 0;

int main()
{
	cin >> str;
	for(int i = 0; i < str.size(); i++)
	{
		if(str[i] == 'a')
			aSize ++;
	}
	if(aSize == 0 || aSize == str.size())
	{
		cout << "0\n";
		return 0;
	}
	int answer = 1111;
	for(int i = 0; i < str.size(); i++)
	{
		int tmp = 0;
		for(int j = 0; j < aSize; j++)
		{
			if(str[(i+j)%str.size()] == 'b')
				tmp ++;
		}
		if(tmp < answer)
			answer = tmp;
	}
	cout << answer << "\n";
}