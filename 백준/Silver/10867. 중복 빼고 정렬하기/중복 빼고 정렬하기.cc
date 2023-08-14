#include <iostream>

using namespace std;

int N;
//0은 plus
int plusAr[1001];
int minusAr[1001];

int main()
{
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		if(num >= 0)
			plusAr[num] = 1;
		else
			minusAr[num * -1] = 1;
	}
	for(int i = 1000; i >= 1; i --)
	{
		if(minusAr[i])
			cout << -i << " ";
	}
	for(int i = 0; i <= 1000; i++)
		if(plusAr[i])
			cout << i << " ";
	cout << endl;
}