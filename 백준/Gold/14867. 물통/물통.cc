#include <iostream>
#include <map>
#include <queue>

using namespace std;

int A, B, A_ans, B_ans;

map<pair<int, int>, int>mp;
queue<pair<pair<int, int>, int> >que;

void insert_ab(int a, int b, int cnt)
{
	if(mp.find(pair<int, int>(a, b)) != mp.end())
			return ;
	mp.insert(make_pair(make_pair(a, b), cnt));
	que.push(pair<pair<int, int>, int>(pair<int, int>(a, b), cnt));
}

void make_all_do(int a, int b, int cnt)
{
	insert_ab(0, b, cnt+1);
	insert_ab(a, 0, cnt+1);
	insert_ab(A, b, cnt+1);
	insert_ab(a, B, cnt+1);
	int a_s = A-a;
	int b_s = B-b;
	if(a <= b_s)
		insert_ab(0, a+b, cnt+1);
	else
		insert_ab(a - b_s, B, cnt+1);
	if(b <= a_s)
		insert_ab(a+b, 0, cnt+1);
	else
		insert_ab(A, b - a_s, cnt+1);
}

void bfs()
{
	mp.insert(make_pair(make_pair(0, 0), 0));
	que.push(pair<pair<int, int>, int>(pair<int, int>(0, 0), 0));
	while(!que.empty())
	{
		int a = que.front().first.first;
		int b = que.front().first.second;
		int cnt = que.front().second;

		if(a == A_ans && b == B_ans)
			return ;
		que.pop();
		make_all_do(a, b, cnt);
	}
}

int main()
{
	cin >> A >> B >> A_ans >> B_ans;
	bfs();
	//mp.insert(make_pair(pair<int, int>(3, 2), 4));
	auto it = mp.find(pair<int, int>(A_ans, B_ans));
	if(it != mp.end())
		cout << it->second << endl;
	else
		cout << "-1" << endl;
}