#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> answer;
int max_sum = -1;
int max_case[11];
int tmp_case[11];
int tmp_ar[11];
int N;
vector<int> vt;

int diff_score()
{
    int a_score = 0;
    int r_score = 0;
    for(int i = 0; i < 11; i ++)
    {
        if(tmp_case[i] == 0)
        {
            if(vt[i])
                a_score += 10-i;
        }
        else
            r_score += 10-i;
    }
    return r_score - a_score;
}

int is_low_num()
{
    int origin = 10;
    for(int i = 10; i >= 0; i --)
    {
        if(tmp_ar[i] == max_case[i])
            continue;
        return tmp_ar[i] - max_case[i];
    }
}

void check()
{
    int score_gap = diff_score();
    // cout << score_gap << endl;
    if(score_gap <= 0 || max_sum > score_gap)
        return ;
    int arrow = 0;
    for(int i = 0; i < 11; i ++)
    {
        if(tmp_case[i] == 0)
        {
            tmp_ar[i] = 0;
            continue;   
        }
        else
        {
            tmp_ar[i] = vt[i]+1;
            arrow += vt[i]+1; 
        }
    }
    if(arrow > N)
        return ;
    tmp_ar[10] += N-arrow;
    if(max_sum != -1 && max_sum == score_gap)
    {
        if(is_low_num() < 0)
            return ;
    }
    max_sum = score_gap;
    for(int i = 0; i < 11; i ++)
    {
        max_case[i] = tmp_ar[i];
    }
}

void make_case(int idx)
{
    if(idx == 11)
    {
        check();
        return;
    }
    tmp_case[idx] = 1;
    make_case(idx+1);
    tmp_case[idx] = 0;
    make_case(idx+1);
    
}

void fill_arrow()
{
    int arrow = 0;
    for(int i = 0; i < 11; i ++)
    {
        answer.push_back(max_case[i]);
    }    
}

vector<int> solution(int n, vector<int> info) {
    N = n;
    for(int i : info)
    {
        vt.push_back(i);
    }
    make_case(0);
    if(max_sum == -1)
    {
        // cout << "here\n";
        answer.push_back(-1);
    }
    else
    {
        // for(int i = 0; i < 11; i ++)
        //     cout << max_case[i] << " ";
        // cout << endl;
        fill_arrow();
    }
    return answer;
}