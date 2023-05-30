#include <iostream>

using namespace std;

int N;
int stt[101];



int main()
{
	cin >> N;
	for(int i = 1; i <= N; i ++)
		cin >> stt[i];
	int s_n;
	cin >> s_n;
	for(int i = 0; i < s_n; i ++)
	{
		int s, num;
		cin >> s >> num;
		if(s == 1) //boy
		{
			for(int j = 1; j * num <= N; j ++)
			{
				stt[j*num] = (stt[j*num] + 1)%2;
			}
		}
		else if(s == 2) //girl
		{
			stt[num] = (stt[num] + 1) % 2;
			int tmp = 1;
			while(1)
			{
				if(num + tmp <= N && num - tmp > 0 && stt[num+tmp] == stt[num-tmp])
				{
					stt[num+tmp] = (stt[num+tmp]+1)%2;
					stt[num-tmp] = (stt[num-tmp]+1)%2;
					tmp ++;
				}
				else
					break;
			}
		}
	}
	for(int j = 0; j * 20 <= N; j ++)
	{
		for(int i = 1; i <= 20 && i + j*20 <= N; i ++)
		{
			cout << stt[j*20 + i] << " ";
		}
		cout << endl;
	}
}