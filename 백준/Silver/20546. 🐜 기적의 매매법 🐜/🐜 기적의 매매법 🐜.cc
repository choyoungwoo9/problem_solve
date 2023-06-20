#include <iostream>

using namespace std;

int ar[14];

int A_cache;
int A_joo;
int B_cache;
int B_joo;

int main()
{
	cin >> A_cache;
	B_cache = A_cache;
	for(int i = 0; i < 14; i ++)
		cin >> ar[i];
	int up = 0;
	int down = 0;
	int before_num = ar[0];
	for(int i = 0; i < 14; i ++)
	{
		if(ar[i] > before_num)
		{
			up ++;
			down = 0;
		}
		else if(ar[i] < before_num)
		{
			down ++;
			up = 0;
		}
		else if(ar[i] == before_num)
		{
			up = 0; down = 0;
		}
		before_num = ar[i];
		// cout << up << " " << down << endl;
		A_joo += A_cache / ar[i];
		A_cache -= (A_cache / ar[i]) * ar[i];
		if(up >= 3)
		{
			B_cache += B_joo * ar[i];
			B_joo = 0;
		}
		if(down >= 3)
		{
			B_joo += B_cache / ar[i];
			B_cache -= (B_cache / ar[i]) * ar[i];
		}
	}
	A_cache += A_joo * ar[13];
	B_cache += B_joo * ar[13];

	// cout << A_cache << " " << B_cache << endl;
	if(A_cache == B_cache)
		cout << "SAMESAME\n";
	else if(A_cache > B_cache)
		cout << "BNP\n";
	else if(B_cache > A_cache)
		cout << "TIMING\n";
}