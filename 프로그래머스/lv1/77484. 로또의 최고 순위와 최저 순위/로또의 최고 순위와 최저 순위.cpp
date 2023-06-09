#include <string>
#include <vector>

using namespace std;

//win_nums표시하고
//lottos돌면서 맞춘거 개수, 0개수 새고
//맞춘거에다가 0더한거, 그냥 맞춘거 등수 구해서 넣으면됨

vector<int> answer;
int z_cnt = 0;
int m_cnt = 0;
int flag[46];

int converter(int cnt)
{
    if(cnt < 2)
        return 6;
    return 6-cnt+1;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    for(int num : win_nums)
    {
        flag[num] = 1;
    }
    
    for(int num : lottos)
    {
        if(num == 0)
            z_cnt ++;
        if(flag[num])
        {
            m_cnt ++;
        }
    }
    
    answer.push_back(converter(z_cnt + m_cnt));
    answer.push_back(converter(m_cnt));
    
    return answer;
}