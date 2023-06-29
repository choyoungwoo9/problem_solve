#include <iostream>
#include <algorithm>

using namespace std;

int cnt1[500001];
int cnt2[500001];

int N, H;

int answer[500001];
int answer2[500001];

int answer3[500001];

int main()
{
	cin >> N >> H;
	for(int i = 0; i < N; i ++)
	{
		int num;
		cin >> num;
		if(i%2 == 0)
		{
			cnt1[num] ++;
		}
		else{
			cnt2[num] ++;
		}
	}
	int sum = 0;
	answer[H] = cnt1[H];
	for(int i = H-1; i >= 1; i--)
	{
		answer[i] = answer[i+1] + cnt1[i];
	}

	answer2[1] = cnt2[H];
	for(int i = 2; i <= H; i++)
	{
		answer2[i] = answer2[i-1] + cnt2[H-i+1];
	}

	for(int i = 1; i <= H; i ++)
		answer3[i] = answer[i] + answer2[i];
	int min_value = 5000000;
	int min_cnt = 0;
	for(int i = 1; i <= H; i ++)
		min_value = min(min_value, answer3[i]);
	for(int i = 1; i <= H; i ++)
		if(min_value == answer3[i])
			min_cnt ++;
	cout << min_value << " " << min_cnt << endl;


	// for(int i = 1; i <= H; i ++)
	// 	cout << answer[i] << " ";
	// cout << endl;

	// for(int i = 1; i <= H; i ++)
	// 	cout << answer2[i] << " ";
	// cout << endl;
}