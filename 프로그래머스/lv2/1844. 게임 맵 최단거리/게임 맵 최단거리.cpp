#include<vector>
#include<iostream>
#include<queue>
using namespace std;


int answer = -1;
int N, M;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};

queue<pair<pair<int, int>, int>> que;
bool visited[100][100];

void bfs(vector<vector<int> >maps)
{
    que.push(make_pair(make_pair(0, 0), 1));
    visited[0][0] = true;
    while(!que.empty())
    {
        int m_i = que.front().first.first;
        int m_j = que.front().first.second;
        int count = que.front().second;
        que.pop();
        if(m_i == N-1&& m_j == M-1)
        {
            answer = count;
            return ;
        }
        for(int i = 0; i < 4; i ++)
        {
            if(m_i + dx[i] < 0 || m_i + dx[i] >= N)
                continue;
            if(m_j + dy[i] < 0 || m_j + dy[i] >= M)
                continue;
            if(maps[m_i + dx[i]][m_j + dy[i]] == 1
                && visited[m_i + dx[i]][m_j + dy[i]] == 0)
            {
                visited[m_i + dx[i]][m_j + dy[i]] = 1;
                que.push(make_pair(make_pair(m_i + dx[i], m_j + dy[i]), count+1));
            }
        }
    }
}

int solution(vector<vector<int> > maps)
{
    N = maps.size();
    M = maps[0].size();
    if(maps[0][0] == 1)
        bfs(maps);
    return answer;
}