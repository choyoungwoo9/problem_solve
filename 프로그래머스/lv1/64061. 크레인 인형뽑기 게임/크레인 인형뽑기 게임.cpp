#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

int answer;


int get_doll(vector<vector<int>> &board, int idx)
{
    int doll = 0;
    idx --;
    for(int j = 0; j < board.size(); j++)
    {
        if(board[j][idx] == 0)
            continue;
        doll = board[j][idx];
        board[j][idx] = 0;
        break;
    }
    return doll;
}

int solution(vector<vector<int>> board, vector<int> moves) {
    
    stack<int> st;
    for(int i = 0;i < moves.size(); i++)
    {
        int doll = get_doll(board, moves[i]);
        if(doll == 0)
            continue;
        // cout << doll << endl;
        if(st.empty() || st.top() != doll)
            st.push(doll);
        else
        {
            st.pop();
            answer = answer + 2;
        }
    }
    return answer;
}