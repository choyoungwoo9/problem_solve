#include <string>
#include <vector>

using namespace std;

string answer = "";

int all_cnt = 0;
int num = 0;

string all_notation = "0123456789ABCDEF";

void recursive_find(int notation, int cur, int m, int p, int t)
{
    if(cur < notation)
    {
        if(all_cnt % m == p-1 && answer.size() < t)
        {
            answer += all_notation[cur];
        }
        all_cnt ++;
        return ;
    }
    recursive_find(notation, cur / notation, m, p, t);
    if(all_cnt % m == p-1 && answer.size() < t)
    {
        answer += all_notation[cur%notation];
    }
    all_cnt ++;
    return ;
}

string solution(int n, int t, int m, int p) {
    
    while(1)
    {
        if(answer.size() == t)
            break;
        recursive_find(n, num, m, p, t);
        num ++;
    }
    return answer;
}