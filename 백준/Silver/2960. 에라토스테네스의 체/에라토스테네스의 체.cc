#include <iostream>

using namespace std;

int ar[1001];

int N, K;
int flag = 0;
int answer;
int cnt = 0;

int main()
{
	cin >> N >> K;
	while(1)
	{
		int m_i = 2;
		for(; m_i <= N; m_i ++)
		{
			if(ar[m_i] == 0)
				break;
		}
		for(int i = 1; m_i * i <= N; i ++)
		{
			if(ar[m_i * i] == 0)
			{
				ar[m_i * i] = 1;
				cnt ++;
			}
			if(cnt == K)
			{
				answer = m_i *i;
				flag = 1;
				break;
			}
		}
		if(flag)
			break;
	}
	cout << answer << endl;
	// 2부터 N까지 모든 정수를 적는다.

	// 아직 지우지 않은 수 중 가장 작은 수를 찾는다. 이것을 P라고 하고, 이 수는 소수이다.

	// P를 지우고, 아직 지우지 않은 P의 배수를 크기 순서대로 지운다.
	// 아직 모든 수를 지우지 않았다면, 다시 2번 단계로 간다.

}