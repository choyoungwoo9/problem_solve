#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> answer;
int cnt[26];
vector<int> solution(vector<string> keymap, vector<string> targets) {
    for(int i = 0; i < keymap.size(); i ++)
    {
        for(int j = 0; j < keymap[i].size(); j ++)
        {
            int cur_idx = keymap[i][j]-'A';
            if(cnt[cur_idx] == 0)
                cnt[cur_idx] = j+1;
            else
                cnt[cur_idx] = min(cnt[cur_idx], j+1);
        }
    }
    
    for(int i = 0; i < targets.size(); i ++)
    {
        answer.push_back(0);
        for(int j = 0; j < targets[i].size(); j++)
        {
            int cur_idx = targets[i][j] - 'A';
            if(cnt[cur_idx] == 0)
            {
                answer[i] = -1;
                break;
            }
            answer[i] += cnt[cur_idx];
        }
    }
    return answer;
}