#include <iostream>

using namespace std;

long long max_store[100000];

long long max_value;

int main()
{
	int n;
	cin >> n;
	cin >> max_store[0];
	max_value = max_store[0];
	for(int i = 1; i < n; i ++)
	{
		cin >> max_store[i];
		if(max_store[i-1] > 0)
		{
			max_store[i] += max_store[i-1];
		}
		if(max_store[i] > max_value)
			max_value = max_store[i];
	}
	cout << max_value << endl;
}