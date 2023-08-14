#include <iostream>

using namespace std;

int weightAr[31][2];
int D, K;

void makeWeight()
{
	weightAr[1][0] = 1;
	weightAr[2][1] = 1;
	for(int i = 3; i <= 30; i++)
	{
		weightAr[i][0] = weightAr[i-1][0] + weightAr[i-2][0];
		weightAr[i][1] = weightAr[i-1][1] + weightAr[i-2][1];
	}
}

void findAnswer(int w1, int w2)
{
	// cout << w1 << " " << w2 << endl;
	int i = 1;
	while(1)
	{
		int aValue = w1 * i;
		// if(aValue > K)
		// 	break;
		int left = K-aValue;
		// cout << aValue << " " << left << endl;
		// cout << w2 << endl;
		if(left % w2 == 0)
		{
			cout << i << endl;
			cout << (K-aValue) / w2 << endl;
			break;
		}
		i ++;
	}
}

int main()
{
	cin >> D >> K;
	makeWeight();
	findAnswer(weightAr[D][0], weightAr[D][1]);
}