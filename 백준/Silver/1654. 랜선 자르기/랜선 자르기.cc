#include <iostream>

using namespace std;

int K, N;

int ar[10000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> K >> N;
	int m_max = 0;
	int num;
	for(int i = 0; i < K ; i ++)
	{
		cin >> num;
		if(num > m_max)
			m_max = num;
		ar[i] = num;
	}

	long long low = 1;
	long long high = m_max;
	long long answer = 0;
	while(low <= high)
	{
		long long mid = ((long long)low + (long long)high) / (long long)2;
		long long count = 0;
		for(int i = 0; i < K; i ++)
		{
			count += (ar[i] / mid);
		}
		if(count < N)
		{
			high = mid -1;
		}
		if(count >= N)
		{
			low = mid + 1;
			if(answer < mid)
				answer = mid;
		}
	}
	cout << answer << endl;
}