#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

typedef struct store{
    string num;
    string h;
    string m;
    string where;
} store;

vector<store> vt;

bool compare(const store &a, const store &b)
{
    if(a.num != b.num)
        return a.num < b.num;
    if(a.h != b.h)
        return a.h < b.h;
    if(a.m != b.m)
        return a.m < b.m;
    return 0;
}

int make_fee(vector<int> &fees, int time)
{
    cout << time << endl;
    if(time <= fees[0])
        return fees[1];
    time = time - fees[0];
    if(time % fees[2] == 0)
        return fees[1] + fees[3] * (time / fees[2]);
    return fees[1] + fees[3] * (time / fees[2] + 1);
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    for(int i = 0; i < records.size(); i ++)
    {
        store a;
        a.h = records[i].substr(0, 2);
        a.m = records[i].substr(3, 2);
        a.num = records[i].substr(6, 4);
        a.where = records[i].substr(11, 1);
        vt.push_back(a);
    }

    sort(vt.begin(), vt.end(), compare);
    
    // for(int i = 0; i < records.size(); i ++)
    // {
    //     cout << vt[i].num << " " << vt[i].h << " " << vt[i].m << endl;
    // }
    
    string before_num = "";
    int before_time = -1;
    int cur_fee = 0;
    int sum_time = 0;
    for(int i = 0; i < records.size(); i ++)
    {
        string &cur_num = vt[i].num;
        int cur_time = ((vt[i].h[0]-'0')*10+vt[i].h[1]-'0') * 60 + (vt[i].m[0]-'0')*10+vt[i].m[1]-'0';
        // cout << cur_time << endl;
        
        //차량의 번호가 이전의 차량기록과 다를때
        if(cur_num != before_num)
        {
            //최대 요금계산
            if(before_time != -1 && before_num != "") //이전의 차량이 출차기록 없을때
            {
                 cout <<  23*60+59 << " " << before_time << endl;
                sum_time += 23*60+59 - before_time;
            }
            if(before_num != "") //처음의 케이스
            {
                cur_fee += make_fee(fees, sum_time);
                answer.push_back(cur_fee);   
            }
            sum_time = 0;
            before_num = cur_num;
            before_time = cur_time;
            cur_fee = 0;
        }
        else //차량의 번호가 이전차량 번호와 같을때
        {
            if(before_time == -1) //입차일때
            {
                before_time = cur_time;
            }
            else //출차일때
            {
                cout << cur_time << " " << before_time << endl;
                sum_time += cur_time - before_time;
                before_time = -1;
            }
        }
    }
    if(before_time != -1) //이전의 차량이 출차기록 없을때
    {
        cout << 23*60+59 << " " << before_time << endl;
        sum_time += 23*60+59 - before_time;
    }
    cur_fee += make_fee(fees, sum_time);
    answer.push_back(cur_fee);
    
    return answer;
}