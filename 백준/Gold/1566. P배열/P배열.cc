#include <iostream>
#include <cmath>

using namespace std;
int N, M;
int input[18][18];

int answer = -1;

int get_bit(int state)
{
	int count = 0;
	for(int i = 0; i < 18; i ++)
	{
		if(state & (1 << i))
			count ++;
	}
	return count;
}

void check_ok(int state)
{
	//printf("ddddddd bit %d state %d\n", get_bit(state), state);
	int count = 0;
	int this_state = 0;
	for(int j = 0; j < M; j ++)
	{
		int sum = 0;
		for(int i = 0; i < N; i ++)
		{
			int flag = 1;
			if(state & (1 << i)) //바꾼것
				flag = -1;
			sum += (input[i][j] * flag);
		}
		if(sum == 0)
			return;
		else if(sum < 0)
		{
			this_state = this_state | (1 << j);
			count ++;
		}
	}
	for(int i = 0; i < N; i ++)
	{
		int sum = 0;
		int i_flag = (state & (1 << i));
		//printf("bit %d state %d this %dcouunt %d\n", get_bit(state), state, this_state, count);
		for(int j = 0; j < M; j ++)
		{
			int j_flag = (this_state & (1 << j));
			int flag;
			if(i_flag && j_flag || !i_flag && !j_flag)
				flag = 1;
			else
				flag = -1;
			sum += (input[i][j] * flag);
		}
		//printf("sum : %d\n", sum);
		if(sum <= 0)
			return ;
	}
	int tmp_answer = get_bit(state) + count;
	if(answer < 0 || answer > tmp_answer)
	{
		answer = tmp_answer;
	}
}

int main()
{
	cin >> N >> M;
	for(int i = 0; i < N; i ++)
	{
		for(int j = 0; j < M; j ++)
		{
			cin >> input[i][j];
		}
	}
	for(int i = 0; i < (int)pow(2, N); i ++) //2의 18승
	{
		check_ok(i);
	}
	cout << answer << endl;
}