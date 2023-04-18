#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// scores_rows는 2차원 배열 scores의 행 길이, scores_cols는 2차원 배열 scores의 열 길이입니다.
int ar[100001];
int check[100001];

int solution(int** scores, size_t scores_rows, size_t scores_cols) {
    for(int i = 0; i <= 100000; i ++)
        ar[i] = 0;
    for(int i = 0; i < scores_rows; i ++)
    {
        if(ar[scores[i][0]] < scores[i][1])
            ar[scores[i][0]] = scores[i][1];
    }
    int max_value = 0;
    for(int i = 100000; i >= 0; i --)
    {
        check[i] = max_value;
        if(max_value < ar[i])
            max_value = ar[i];
    }

    int answer = 1;
    int flag = 1;
    for(int i = 0; i < scores_rows; i ++)
    {
       if(scores[i][0] > scores[0][0] && scores[i][1] > scores[0][1])
        {
            flag = 0;
            break ;
        }
    }
    if(flag == 0)
        return -1;
    for(int i = 0; i < scores_rows; i ++)
    {
        if(scores[0][0] + scores[0][1] < scores[i][0]+scores[i][1])
        {
            if(check[scores[i][0]] <= scores[i][1])
                answer ++;
        }
    }
    return answer;
}