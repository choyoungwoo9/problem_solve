#include <iostream>
#include <string>

using namespace std;

string N;
int B;

int main()
{
	cin >> N >> B;
	int all = 0;

	int digit = 1;
	for(int i = N.size()-1; i >= 0; i --)
	{
		int n;
		if(N[i] >= '0' && N[i] <= '9')
		{
			n = N[i] - '0';
		}
		else
		{
			n = 10 + N[i]-'A';
		}
		all += digit * n;
		digit = digit * B;
	}
	cout << all << endl;
}