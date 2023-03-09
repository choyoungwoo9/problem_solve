#include <iostream>
using namespace std;
int stack[10000];

int point = -1;

void push(int num)
{
	stack[++point] = num;
	return ;
}

int pop()
{
	if(point == -1)
		return point;
	return stack[point--];
}

int size()
{
	return point + 1;
}

int empty()
{
	if(point == -1)
		return 1;
	return 0;
}

int top()
{
	if(point == -1)
		return -1;
	return stack[point];
}

int main()
{
	int N;
	cin >> N;
	for(int i = 0; i < N; i ++)
	{
		string str;
		cin >> str;
		if(str == "push")
		{
			int num;
			cin >> num;
			push(num);
		}
		else if(str == "pop")
		{
			cout << pop() << endl;
		}
		else if(str == "size")
		{
			cout << size() << endl;
		}
		else if(str == "empty")
		{
			cout << empty() << endl;
		}
		else if(str == "top")
		{
			cout << top() << endl;
		}
	}
}