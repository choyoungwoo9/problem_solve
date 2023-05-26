#include <iostream>
#include <algorithm>

using namespace std;

string ar[1000];


int main()
{
	cin >> ar[0];
	for(int i = 0; i < ar[0].size(); i ++)
	{
		ar[i] = ar[0].substr(i);
	}
	int sz = ar[0].size();

	sort(ar, ar+sz);
	for(int i = 0; i < sz; i ++)
	{
		cout << ar[i] << "\n";
	}
}