#include <iostream>

using namespace std;

int N, M;
double probNode[4][4];

double probability[4] = {25, 25, 25, 25};

void simulate()
{
	double sum[4];
	for(int i = 0; i < 4; i++)
		sum[i] = 0;

	for(int i = 0; i < 4; i++)
	{
		double curProb = probability[i];
		for(int j = 0; j < 4; j++)
		{
			sum[j] += probNode[i][j] * curProb;
		}
	}

	for(int i = 0; i < 4; i++)
		probability[i] = sum[i];
}

int main()
{
	cin >> N >> M;
	for(int i = 0; i < M; i++)
	{
		char n1, n2;
		double prob;

		cin >> n1 >> n2;
		cin >> prob;
		probNode[n1-'A'][n2-'A'] = prob;
	}
	for(int i = 0; i < N; i++)
		simulate();
	cout << fixed;
	cout.precision(2);
	for(int i = 0; i < 4; i++)
		cout << probability[i] << "\n";
}