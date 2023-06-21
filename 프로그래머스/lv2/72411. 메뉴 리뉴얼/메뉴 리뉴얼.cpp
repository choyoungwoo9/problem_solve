#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
vector<string> answer;

int comb[10];

map<int, int> mp;

int idx = 0;

void combi(int n, int r, int depth, int num, string orders)
{
    if(depth == r)
    {
        mp[idx] ++;
        // cout << idx << " " <<mp[idx] << endl;
        return ;
    }
    for(int i = num+1; i < n; i ++)
    {
        idx |= (1 << (orders[i]-'A'));
        combi(n, r, depth+1, i, orders);
        idx &= ~(1 << (orders[i]-'A'));
    }
}

void logic(int r, vector<string> orders)
{
    mp.clear();
    for(int i = 0; i < orders.size(); i ++)
    {
        combi(orders[i].size(), r, 0, -1, orders[i]);
    }
    int m_cnt = 0;
    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        m_cnt = max(m_cnt, it->second);
    }
    if(m_cnt < 2)
        return ;
    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        if(m_cnt == it->second)
        {
            string str;
            for(int i = 0; i < 26; i ++)
            {
                if(it->first & (1 << i))
                    str += ('A' + i);
            }
            answer.push_back(str);
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    
    for(int i = 0; i < course.size(); i ++)
    {
        logic(course[i], orders);
    }
    sort(answer.begin(), answer.end());
    return answer;
}