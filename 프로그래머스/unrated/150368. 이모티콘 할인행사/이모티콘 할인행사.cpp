#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> answer;
int N;

int sale_rate[7];

int m_cnt = 0;
int m_price = 0;

int cnt = 0;
int price = 0;

void cur_user(vector<int> &user, vector<int> &emoticons)
{
    int cur_price = 0;
    for(int i = 0; i < emoticons.size(); i ++)
    {
        if(sale_rate[i] < user[0])
            continue;
        cur_price += (emoticons[i] / 100) * (100-sale_rate[i]);
    }
    if(cur_price >= user[1])
        cnt ++;
    else
        price += cur_price;
}

void cur_case(vector<vector<int>> &users, vector<int> &emoticons)
{
    cnt = 0;
    price = 0;
    for(int i = 0; i < users.size(); i ++)
    {
        cur_user(users[i], emoticons);
    }
    if(cnt == m_cnt)
    {
        m_price = max(m_price, price);
    }
    if(cnt > m_cnt)
    {
        m_cnt = cnt;
        m_price = price;
    }
}

void do_permutation(int depth, vector<vector<int>> &users, vector<int> &emoticons)
{
    if(depth == N)
    {
        cur_case(users, emoticons);
        return ;
    }
    for(int i = 1; i <= 4; i ++)
    {
        sale_rate[depth] = i*10;
        do_permutation(depth+1, users, emoticons);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    N = emoticons.size();
    do_permutation(0, users, emoticons);
    answer.push_back(m_cnt);
    answer.push_back(m_price);
    return answer;
}