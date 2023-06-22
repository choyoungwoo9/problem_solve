#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<string> answer;

vector<string> split(string str, string del)
{
    vector<string> ret;
    for(int idx = str.find(del); idx != string::npos;idx = str.find(del))
    {
        ret.push_back(str.substr(0, idx));
        str = str.substr(idx+del.length());
    }
    ret.push_back(str);
    return ret;
}

typedef struct info
{
    string id;
    int inout;
}   info;

vector<info> info_ar;
map<string, string> id_to_nickname;

vector<string> solution(vector<string> record) {
    
    for(int i = 0; i < record.size(); i ++)
    {
        vector<string> vt = split(record[i], " ");
        if(vt[0] == "Enter")
        {
            id_to_nickname[vt[1]] = vt[2];
            info i;
            i.id = vt[1];
            i.inout = 0;
            info_ar.push_back(i);
        }
        else if(vt[0] == "Leave")
        {
            info i;
            i.id = vt[1];
            i.inout = 1;
            info_ar.push_back(i);
        }
        else if(vt[0] == "Change")
        {
            id_to_nickname[vt[1]] = vt[2];
        }
        else{
            cout << "Error" << endl;
        }
    }
    
    for(int i = 0; i < info_ar.size(); i ++)
    {
        if(info_ar[i].inout == 0)
        {
            answer.push_back(id_to_nickname[info_ar[i].id] + "님이 들어왔습니다.");
        }
        else if(info_ar[i].inout == 1)
        {
            answer.push_back(id_to_nickname[info_ar[i].id] + "님이 나갔습니다.");
        }
    }
    
    return answer;
}