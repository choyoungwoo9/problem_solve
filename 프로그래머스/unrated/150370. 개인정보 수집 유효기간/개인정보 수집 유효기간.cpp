#include <string>
#include <vector>
#include <iostream>
// #include <cstdlib>

using namespace std;

vector<int> answer;

int tms[26];

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    
    int today_y = atoi(today.substr(0, 4).c_str());
    int today_m = atoi(today.substr(5, 2).c_str());
    int today_d = atoi(today.substr(8, 2).c_str());
    
    int today_days = today_y * 12 * 28 + today_m * 28 + today_d;
    
    for(int i = 0; i < terms.size(); i ++)
    {
        tms[terms[i][0]-'A'] = atoi(terms[i].substr(2).c_str());
    }
    
    for(int i = 0; i < privacies.size(); i ++)
    {
        int y = atoi(privacies[i].substr(0, 4).c_str());
        int m = atoi(privacies[i].substr(5, 2).c_str());
        int d = atoi(privacies[i].substr(8, 2).c_str());
        char t = privacies[i][11];
        m += tms[t-'A'];
        m --;
        y += m / 12;
        m = m % 12;
        m ++;
        if(y * 12 * 28 + m * 28 + d <= today_days)
            answer.push_back(i+1);
    }
    
    return answer;
}