#include <string>
#include <vector>
#include <iostream>
using namespace std;
//같으면 사전순으로 빠른 순
//RT 비동의시 R 동의시 T
//123 비동의 // 567동의
//각 선택으로 점수올림
//마지막에 점수끼리 비교
//string 만듬

//RT CF JM AN
int cnt[8];

int trans_alpha_to_int(char ch)
{
    string str("RTCFJMAN");
    for(int i = 0; i < 8; i ++)
    {
        if(str[i] == ch)
            return i;
    }
        
}

void get_cnt(string info, int choice)
{
    //선택한거에서 4뺌
    //0보다 작은지 큰지 검사함
    //abs해서 해당 값 cnt올림
    choice -= 4;
    if(choice < 0)
    {
        cnt[trans_alpha_to_int(info[0])] += choice * -1;
    }
    else if(choice > 0)
    {
        cnt[trans_alpha_to_int(info[1])] += choice;
    }
}


string answer = "";

void get_answer()
{
    if(cnt[0] > cnt[1])
        answer += 'R';
    else if(cnt[1] > cnt[0])
        answer += 'T';
    else
        answer += 'R';
    
    if(cnt[2] > cnt[3])
        answer += 'C';
    else if(cnt[3] > cnt[2])
        answer += 'F';
    else
        answer += 'C';
    
    if(cnt[4] > cnt[5])
        answer += 'J';
    else if(cnt[5] > cnt[4])
        answer += 'M';
    else
        answer += 'J';
    
    if(cnt[6] > cnt[7])
        answer += 'A';
    else if(cnt[7] > cnt[6])
        answer += 'N';
    else
        answer += 'A';
}

string solution(vector<string> survey, vector<int> choices) {
    for(int i = 0; i < survey.size(); i ++)
        get_cnt(survey[i], choices[i]);
    // for(int i = 0; i < 8; i ++)
    //     cout << cnt[i] << " ";
    get_answer();
    return answer;
}