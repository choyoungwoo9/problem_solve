#include <iostream>

using namespace std;

int pizzaCaseCount1[2000000];
int pizzaCaseCount2[2000000];

int customerSize;
int m;
int pizzaSize1[1000];
int n;
int pizzaSize2[1000];

void getPizzaCaseCount1()
{
	//i조각 만큼 사용했을때 경우의 수
	for(int i = 1; i <= m; i ++)
	{
		int sum = 0;
		for(int j = 0; j < i; j++)
			sum += pizzaSize1[j];
		pizzaCaseCount1[sum] ++;
		//전체조각을 사용했을때 예외처리
		if(i == m)
			return ;
		//순회하며 i조각의 모든 경우 찾음
		for(int j = 0; j < m-1; j ++)
		{
			sum -= pizzaSize1[j%m];
			sum += pizzaSize1[(j+i)%m];
			pizzaCaseCount1[sum] ++;
		}
	}
}

void getPizzaCaseCount2()
{
	//i조각 만큼 사용했을때 경우의 수
	for(int i = 1; i <= n; i ++)
	{
		int sum = 0;
		for(int j = 0; j < i; j++)
			sum += pizzaSize2[j];
		pizzaCaseCount2[sum] ++;
		//전체조각을 사용했을때 예외처리
		if(i == n)
			return ;
		//순회하며 i조각의 모든 경우 찾음
		// cout << i << "번째 시작 "<< endl;
		for(int j = 0; j < n-1; j ++)
		{
			sum -= pizzaSize2[j%n];
			sum += pizzaSize2[(j+i)%n];
			// cout << sum << endl;
			pizzaCaseCount2[sum] ++;
		}
	}
}

int getAnswer()
{
	int answer = 0;
	for(int i = 1; i < customerSize; i ++)
	{
		answer += (pizzaCaseCount1[i] * pizzaCaseCount2[customerSize-i]);
		// cout << i << "번째 " << pizzaCaseCount1[i] << " 와 " << pizzaCaseCount2[customerSize-i] << endl;
	}
	answer += pizzaCaseCount1[customerSize];
	answer += pizzaCaseCount2[customerSize];
	return answer;
}

int main()
{
	cin >> customerSize;
	cin >> m >> n;
	for(int i = 0; i < m; i ++)
		cin >> pizzaSize1[i];
	for(int i = 0; i < n; i ++)
		cin >> pizzaSize2[i];
	getPizzaCaseCount1();
	getPizzaCaseCount2();
	cout << getAnswer() << endl;
}