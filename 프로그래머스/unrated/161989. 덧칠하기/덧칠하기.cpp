#include <string>
#include <vector>

using namespace std;

int answer = 0;
int solution(int n, int m, vector<int> section) {
    
    int now = -1;
    for(int idx : section)
    {
        if(now < idx)
        {
            answer ++;
            now = idx + m - 1;
        }
    }
    return answer;
}