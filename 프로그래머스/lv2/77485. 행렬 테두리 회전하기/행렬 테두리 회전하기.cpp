#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> answer;

int mp[101][101];
int H, W;

void print_mp()
{
    for(int j = 1; j <= H; j ++)
    {
        for(int i = 1; i <= W; i ++)
        {
            cout << mp[j][i] << " ";
        }
        cout << endl;
    }
}

void spin(int y1, int x1, int y2, int x2)
{
    //위에서 오른쪽으로 가는 회전
    int tmp_min = 1000000000;
    int before_num = mp[y1+1][x1];
    for(int i = x1; i < x2; i ++)
    {
        int cur_num = mp[y1][i];
        tmp_min = min(tmp_min, cur_num);
        mp[y1][i] = before_num;
        before_num = cur_num;
    }
    for(int j = y1; j < y2; j++)
    {
        int cur_num = mp[j][x2];
        tmp_min = min(tmp_min, cur_num);
        mp[j][x2] = before_num;
        before_num = cur_num;
    }
    for(int i = x2; i > x1; i --)
    {
        int cur_num = mp[y2][i];
        tmp_min = min(tmp_min, cur_num);
        mp[y2][i] = before_num;
        before_num = cur_num;
    }
    for(int j = y2; j > y1; j--)
    {
        int cur_num = mp[j][x1];
        tmp_min = min(tmp_min, cur_num);
        mp[j][x1] = before_num;
        before_num = cur_num;
    }
    answer.push_back(tmp_min);
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    H = rows;
    W = columns;
    int cnt = 1;
    for(int j = 1; j <= H; j ++)
    {
        for(int i = 1; i <= W; i ++)
        {
            mp[j][i] = cnt;
            cnt ++;
        }
    }
    for(int i = 0; i < queries.size(); i ++)
    {
        spin(queries[i][0], queries[i][1], queries[i][2], queries[i][3]);
    }
    //print_mp();
    return answer;
}