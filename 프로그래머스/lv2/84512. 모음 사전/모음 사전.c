#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int answer = 0;
int end_flag = 0;

void check_str(int count, char *tmp_str, char *str)
{
    if(strcmp(tmp_str, str) == 0)
    {
        end_flag = 1;
        return ;   
    }
    if(count == 5)
        return ;
    for(int i = 0; i < 5; i ++)
    {
        if(end_flag)
            return;
        tmp_str[count] = i+'0';
        tmp_str[count+1] = '\0';
        answer ++;
        check_str(count+1, tmp_str, str);
    }
}

int solution(const char* word) {
    char *str = strdup(word);
    for(int i = 0; str[i]; i ++)
    {
        if(str[i] == 'A')
            str[i] = '0';
        else if(str[i] == 'E')
            str[i] = '1';
        else if(str[i] == 'I')
            str[i] = '2';
        else if(str[i] == 'O')
            str[i] = '3';
        else if(str[i] == 'U')
            str[i] = '4';
    }
    char my_str[6];
    my_str[0] = 0;
    check_str(0, my_str, str);
    return answer;
}