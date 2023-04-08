#include <iostream>

using namespace std;

int N;

int ar[51];
int ar2[51];

int get_rank(int index)
{
	int rank = 1;
	for(int i = 0; i < N; i ++)
	{
		if(ar[i] > ar[index] && ar2[i] > ar2[index])
			rank ++;
	}
	return rank;
}

int main()
{
	cin >> N;
	for(int i = 0; i < N; i ++)
		cin >> ar[i] >> ar2[i];
	for(int i = 0; i < N; i ++)
	{
		cout << get_rank(i) << " ";
	}
	cout << "\n";
}