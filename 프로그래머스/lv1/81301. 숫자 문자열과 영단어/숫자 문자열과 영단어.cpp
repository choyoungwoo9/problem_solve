#include <string>
#include <vector>

using namespace std;

string ar[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int solution(string s) {
    int answer = 0;
    for(int i = 0; i < 10;)
    {
        int idx = s.find(ar[i]);
        if(idx == string::npos)
        {
            i ++;
            continue;
        }
        s = s.substr(0, idx) + to_string(i) + s.substr(idx+ar[i].size());
    }
    answer = atoi(s.c_str());
    return answer;
}