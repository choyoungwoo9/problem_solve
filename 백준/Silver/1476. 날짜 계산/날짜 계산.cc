#include <iostream>

using namespace std;

int E, S, M;

int n1, n2, n3;

int main()
{
	cin >> E >> S >> M;
	int year = 1;
	while(1)
	{
		if(n1 == E - 1 && n2 == S - 1 && n3 == M - 1)
			break;
		n1 = (n1 + 1) % 15;
		n2 = (n2 + 1) % 28;
		n3 = (n3 + 1) % 19;
		year ++;
	}
	cout << year << endl;
}