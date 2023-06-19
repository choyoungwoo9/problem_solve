#include <iostream>
#include <set>
using namespace std;

int N, M;
int ar[100001];
int masking = (1 << 20) - 1;

void in(int t_num, int s_num)
{
	s_num --;
	ar[t_num] |= (1 << s_num);
	ar[t_num] &= masking;
}

void out(int t_num, int s_num)
{
	s_num --;
	ar[t_num] = ar[t_num] & ~(1 << s_num);
}

void back(int t_num)
{
	ar[t_num] = ar[t_num] << 1;
	ar[t_num] &= masking;
}

void front(int t_num)
{
	ar[t_num] = ar[t_num] >> 1;
}


int main()
{
	cin >> N >> M;

	for(int i = 0; i < M; i ++)
	{
		int type;
		int t_num, s_num;
		cin >> type;
		if(type == 1)
		{
			cin >> t_num >> s_num;
			in(t_num, s_num);
		}
		else if(type == 2)
		{
			cin >> t_num >> s_num;
			out(t_num, s_num);
		}
		else if(type == 3)
		{
			cin >> t_num;
			back(t_num);
		}
		else if(type == 4)
		{
			cin >> t_num;
			front(t_num);
		}
	}

	set<int> st;
	for(int i = 1; i <= N; i ++)
	{
		st.insert(ar[i]);
	}
	cout << st.size() << endl;
}