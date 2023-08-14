#include <iostream>
#include <algorithm>

using namespace std;

double leftEnd = 0;
double rightEnd;

double ar[6];

void fold(double point)
{
	for(int i = 0; i < 6; i++)
	{
		if(ar[i] <= point)
			continue;
		double distance = ar[i] - point;
		ar[i] = point - distance;
	}
	double distance = rightEnd - point;
	double tmpLeft = point - distance;
	leftEnd = min(leftEnd, tmpLeft);
	rightEnd = point;
}

int main()
{
	cin >> rightEnd;
	for(int i = 0; i < 6; i++)
		cin >> ar[i];
	for(int i = 0; i < 3; i++)
	{
		if(ar[i*2] == ar[i*2+1])
			continue;
		double mid = (ar[i*2] + ar[i*2+1]) / (double)2;
		// cout << mid << endl;
		fold(mid);
		// for(int i = 0; i < 6; i++)
		// {
		// 	cout << ar[i] << " ";
		// }
		// cout << endl;
		// cout << leftEnd << " " << rightEnd << endl;
	}
	cout << fixed;
	cout.precision(1);
	cout << rightEnd - leftEnd << endl;

}