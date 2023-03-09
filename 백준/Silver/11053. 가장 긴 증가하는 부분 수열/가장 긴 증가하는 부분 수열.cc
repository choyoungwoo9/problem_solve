#include <iostream>

using namespace std;

typedef struct info
{
	int num;
	int d;
}	info;

info table[1000];
int N;

int answer = 0;

int main()
{
	cin >> N;
	for(int i = 0; i < N; i ++)
	{
		int num;
		cin >> num;
		table[i].num = num;
		int max = 0;
		for(int j = 0; j < i; j ++)
		{
			//printf("%d %d %d %d\n", table[j].num, num, table[j].d, max);
			if(table[j].num < num && table[j].d > max)
			{
				max = table[j].d;
			}
		}
		table[i].d = max + 1;
		if(table[i].d > answer)
			answer = table[i].d;
	}
	cout << answer << endl;
}