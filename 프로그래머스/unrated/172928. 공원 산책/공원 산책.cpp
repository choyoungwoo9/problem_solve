#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> answer;

int H, W;
int cur_y, cur_x;

//E W N S
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void mv(vector<string> &park, int dir, int dis)
{
    int ny = cur_y;
    int nx = cur_x;
    for(int i = 0; i < dis; i ++)
    {
        ny += dy[dir];
        nx += dx[dir];
        if(ny < 0 || ny >= H || nx < 0 || nx >= W)
            return ;
        if(park[ny][nx] == 'X')
            return;
    }
    cur_y = ny;
    cur_x = nx;
}

vector<int> solution(vector<string> park, vector<string> routes) {
    H = park.size();
    W = park[0].size();
    
    for(int j = 0; j < H; j ++)
    {
        for(int i = 0; i < W; i ++)
        {
            if(park[j][i] == 'S')
            {
                cur_y = j;
                cur_x = i;
            }
        }
    }
    
    //cout << cur_y << " " << cur_x << endl;
    for(int i = 0; i < routes.size(); i ++)
    {
        int idx;
        if(routes[i][0] == 'E')
            idx = 0;
        else if(routes[i][0] == 'W')
            idx = 1;
        else if(routes[i][0] == 'N')
            idx = 2;
        else if(routes[i][0] == 'S')
            idx = 3;
        int dis = routes[i][2] - '0';
       // cout << "idx " << idx << " dis " << dis << endl;
        mv(park, idx, dis);
        //cout << cur_y << " " << cur_x << endl;
    }
    answer.push_back(cur_y);
    answer.push_back(cur_x);
    return answer;
}