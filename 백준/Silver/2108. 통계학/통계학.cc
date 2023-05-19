#include <iostream>
#include <algorithm>
using namespace std;

long long sum;
int mmin = 4001;
int mmax = -4001;

int ar1[500000];

int ar3[4001];
int ar4[4001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	for(int i = 0; i < N; i ++)
	{
		cin >> ar1[i];
		if(ar1[i] >= 0)
			ar4[ar1[i]] ++;
		else
			ar3[-1 * ar1[i]] ++;
		sum += ar1[i];
		if(ar1[i] > mmax)
			mmax = ar1[i];
		if(ar1[i] < mmin)
			mmin = ar1[i];
	}

	sort(ar1, ar1+N);

	int first_index = 0;
	int second_index = 0;
	int tmp = -1;
	for(int i = 4000; i >= 0; i --)
	{
		if(ar4[i] > tmp)
		{
			first_index = i;
			second_index = 4002;
			tmp = ar4[i]; 
		}
		else if(ar4[i] == tmp)
		{
			second_index = first_index;
			first_index = i;
		}
	}

	for(int i = 0; i < 4001; i ++)
	{
		if(ar3[i] > tmp)
		{
			first_index = i * -1;
			second_index = 4002;
			tmp = ar3[i]; 
		}
		else if(ar3[i] == tmp)
		{
			second_index = first_index;
			first_index = i * -1;
		}
	}

	int flag = 0;
	
	if((double)sum / N - sum / N >= 0.5)
		flag = 1;
	if((double)sum / N - sum / N <= -0.5)
		flag = -1;
	cout << sum / N + flag << endl;
	cout << ar1[N/2] << endl;
	if(second_index == 4002)
		cout << first_index << endl;
	else
		cout << second_index << endl;
	cout << mmax - mmin << endl;
}