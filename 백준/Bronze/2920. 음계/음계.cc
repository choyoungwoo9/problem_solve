#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	for(int i = 0; i < 8; i ++)
	{
		string tmp;
		cin >> tmp;
		str += tmp;
	}
	if(str == "12345678")
		cout << "ascending" << endl;
	else if(str == "87654321")
		cout << "descending" << endl;
	else
		cout << "mixed" << endl;
}