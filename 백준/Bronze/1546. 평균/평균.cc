#include<iostream>

using namespace std;

int N;

int ar[1000];
double ar2[1000];
double m_max;

int main()
{
	cin >> N;
	for(int i = 0; i < N; i ++)
	{
		cin >> ar[i];
		if(ar[i] > m_max)
			m_max = ar[i];
	}

	double sum = 0;
	for(int i = 0; i < N; i ++)
	{
		sum += (ar[i] / m_max) * 100;

	}

	cout << sum / (double) N << endl;
}