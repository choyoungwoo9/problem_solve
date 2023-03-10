#include <iostream>
#include <stack>

using namespace std;

bool is_use[100001];

int N;
int input[100001];
bool order_storage[200000];
int o_p;

int point = 1;

stack<int> st;

int main()
{
	cin >> N;
	for(int i = 1; i <= N; i ++)
	{
		int num;
		cin >> num;
		input[i] = num;
	}
	for(int i = 1; i <= N; i ++)
	{
		if(st.empty() || st.top() != input[i])
		{
			if(is_use[input[i]] == 1)
			{
				cout << "NO" << endl;
				return 0;
			}
			for(; point <= input[i]; point ++)
			{
				st.push(point);
				is_use[point] = 1;
				order_storage[o_p++] = 1;
			}
		}
		st.pop();
		order_storage[o_p++] = 0;
	}
	for(int i = 0; i < N * 2; i ++)
	{
		if(order_storage[i])
			cout << "+\n";
		else
			cout << "-\n";
	}
}