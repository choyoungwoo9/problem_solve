#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int min_y = 100;
int min_x = 100;
int max_y = -1;
int max_x = -1;
vector<int> answer;

vector<int> solution(vector<string> wallpaper) {
    for(int j = 0; j < wallpaper.size(); j ++)
    {
        for(int i = 0; i < wallpaper[0].size(); i ++)
        {
            if(wallpaper[j][i] == '#')
            {
                min_y = min(min_y, j);
                min_x = min(min_x, i);
                max_y = max(max_y, j+1);
                max_x = max(max_x, i+1);
            }
        }
    }
    answer.push_back(min_y);
    answer.push_back(min_x);
    answer.push_back(max_y);
    answer.push_back(max_x);
    return answer;
}