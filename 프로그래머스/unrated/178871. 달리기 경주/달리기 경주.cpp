#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, int> m1;
map<int, string> m2;

vector<string> solution(vector<string> players, vector<string> callings) {
    for(int i = 0; i < players.size(); i ++)
    {
        m1[players[i]] = i;
        m2[i] = players[i];
    }
    
    for(int i = 0; i < callings.size(); i ++)
    {
        string now_player = callings[i];
        int now_score = m1[now_player];
        string player2 = m2[now_score-1];
        m2[now_score-1] = now_player;
        m2[now_score] = player2;
        m1[now_player] = m1[now_player]-1;
        m1[player2] = m1[player2]+1;
    }
    vector<string> answer;
    for(int i = 0; i < players.size(); i ++)
    {
        answer.push_back(m2[i]);
    }
    return answer;
}