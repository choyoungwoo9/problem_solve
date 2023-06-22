#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int p, m;

vector<pair<int, vector<string> > > room;
map<string, int> mp;


int main()
{
	cin >> p >> m;
	for(int i = 0; i < p; i ++)
	{
		int l;
		string n;
		cin >> l >> n;
		mp[n] = l;
		int flag = 0;
		for(int j = 0; j < room.size(); j ++)
		{
			if(room[j].first + 10 < l || room[j].first - 10 > l)
				continue;
			if(room[j].second.size() == m)
				continue;
			flag = 1;
			room[j].second.push_back(n);
			break;
		}
		if(flag == 0)
		{
			vector<string> vt;
			vt.push_back(n);
			room.push_back(pair<int, vector<string> >(l, vt));
		}
	}

	for(int i = 0; i <room.size(); i ++)
		sort(room[i].second.begin(), room[i].second.end());

	for(int i = 0; i < room.size(); i ++)
	{
		if(room[i].second.size() == m)
			cout << "Started!\n";
		else
			cout << "Waiting!\n";
		for(int j = 0; j < room[i].second.size(); j ++)
		{
			cout << mp[room[i].second[j]] << " " << room[i].second[j] << "\n";
		}
	}
}