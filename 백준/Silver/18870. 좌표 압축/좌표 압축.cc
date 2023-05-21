#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int N;
int ar[1000000];
set<int> st;
map<int, int> mp;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i ++)
	{
		cin >> ar[i];
		st.insert(ar[i]);
	}
	int i = 0;
	for(auto it = st.begin(); it != st.end(); it++)
	{
		mp.insert({*it, i});
		i ++;
	}
	for(int i = 0; i < N; i ++)
	{
		cout << mp[ar[i]] << " ";
	}
	cout << endl;
}