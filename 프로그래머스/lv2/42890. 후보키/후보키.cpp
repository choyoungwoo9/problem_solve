#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

int answer = 0;
int visited[8];

vector<vector<int> >answer_vt;

int is_unique(vector<int> &vt, vector<vector<string>> &relation)
{
    map<string, int> mp;
    for(int i = 0; i < relation.size(); i ++)
    {
        string str;
        for(int j = 0; j < vt.size(); j ++)
        {
            str += relation[i][vt[j]];
        }
        mp[str] ++;
        if(mp[str] != 1)
            return 0;
    }
    answer_vt.push_back(vt);
    return 1;
}

int is_min(vector<int> &vt)
{
    for(int i = 0; i < answer_vt.size(); i ++)
    {
        int flag = 0;
        for(int j = 0; j < answer_vt[i].size(); j ++)
        {
            for(int k = 0; k < vt.size(); k ++)
            {
                flag = 0;
                if(answer_vt[i][j] == vt[k])
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
                continue;
            else
                break;
        }
        if(flag == 1)
            return 0;
    }
    return 1;
}

void combi(int n, int r, int idx, vector<int> &vt, vector<vector<string>> &relation)
{
    if(vt.size() == r)
    {
        if(is_min(vt) && is_unique(vt, relation))
        {
            answer ++;
        }
        return ;
    }
    for(int i = idx+1; i < n; i ++)
    {
        vt.push_back(i);
        combi(n, r, i, vt, relation);
        vt.pop_back();
    }
}


int solution(vector<vector<string>> relation) {
    
    for(int i = 1; i <= relation[0].size(); i ++)
    {
        vector<int> vt;
        combi(relation[0].size(), i, -1, vt, relation);   
    }
    return answer;
}