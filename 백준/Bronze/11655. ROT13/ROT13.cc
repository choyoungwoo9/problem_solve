#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string str;

int main()
{
	getline(cin, str);
	for(int i = 0; i < str.size(); i ++)
	{
		if(isupper(str[i]))
			cout << (char)('A'+((str[i]-'A'+13)%26));
		else if(islower(str[i]))
			cout << (char)('a'+((str[i]-'a'+13)%26));
		else
		{
			cout << str[i];
		}
	}
	cout << endl;
}