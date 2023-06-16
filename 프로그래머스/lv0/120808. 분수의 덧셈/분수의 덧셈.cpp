#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> answer;

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    int ret_numer = numer1 * denom2 + numer2 * denom1;
    int ret_denom = denom1 * denom2;
    for(int i = 2; i <= ret_denom; i ++)
    {
        if(ret_numer % i == 0 && ret_denom % i == 0)
        {
            ret_numer /= i;
            ret_denom /= i;
            i --;
        }
    }
    answer.push_back(ret_numer);
    answer.push_back(ret_denom);
    return answer;
}