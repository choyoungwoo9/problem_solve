#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

stack<int> st1;
stack<int> st2;

void delete_zero()
{
    while(!st1.empty())
    {
        if(st1.top() == 0)
            st1.pop();
        else
            break;
    }
    while(!st2.empty())
    {
        if(st2.top() == 0)
            st2.pop();
        else
            break;
    }
}

void pop_stack(stack<int> &st, int cap)
{
    if(st.empty())
        return;
    while(!st.empty())
    {
        if(st.top() <= cap)
        {
            cap -= st.top();
            st.pop();
        }
        else
        {
            st.top() -= cap;
            return ;
        }
    }
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    for(int i = 0; i < n; i ++)
    {
        st1.push(deliveries[i]);
        st2.push(pickups[i]);
    }
    while(1)
    {
        delete_zero();
        if(st1.empty() && st2.empty())
            break;
        answer += (max(st1.size(), st2.size()) * 2);
        pop_stack(st1, cap);
        pop_stack(st2, cap);
    }
    return answer;
}