#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
// 2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
// 3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
// 4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
// 5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
// 6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
//      만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
// 7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
string answer = "";

void step1(string &new_id)
{
    for(int i = 0; i < new_id.size(); i ++)
    {
        if(new_id[i] >= 'A' && new_id[i] <= 'Z')
            new_id[i] = new_id[i] - ('A' - 'a');
    }
}

void step2(string &new_id)
{
    for(int i = 0; i < new_id.size(); i ++)
    {
        if(new_id[i] >= 'a' && new_id[i] <= 'z')
            answer = answer + new_id[i];
        else if(new_id[i] >= '0' && new_id[i] <= '9')
            answer = answer + new_id[i];
        else if(new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
            answer = answer + new_id[i];
    }
}
void step3(string &new_id)
{
    // cout << new_id << endl;
    for(int idx = new_id.find(".."); idx != string::npos; idx = new_id.find(".."))
    {
        new_id = new_id.substr(0, idx)+new_id.substr(idx+1);
        // cout << new_id << endl;
    }
}
void step4(string &new_id)
{
    while(1)
    {
        if(new_id.size() != 0 && new_id[0] == '.')
        {
            new_id = new_id.substr(1);
        }
        else if(new_id.size() != 0 && new_id[new_id.size()-1] == '.')
        {
            new_id = new_id.substr(0, new_id.size()-1);
        }
        else
            return ;
    }
}
void step5(string &new_id)
{
    if(new_id.size() == 0)
        new_id = "a";
}
void step6(string &new_id)
{
    if(new_id.size() >= 16)
        new_id = new_id.substr(0, 15);
    step4(new_id);
}
void step7(string &new_id)
{
    while(new_id.size() < 3)
    {
        new_id = new_id + new_id[new_id.size()-1];
    }
    
}



string solution(string new_id) {
    
    step1(new_id);
    step2(new_id);
    step3(answer);
    step4(answer);
    step5(answer);
    step6(answer);
    step7(answer);
    return answer;
}