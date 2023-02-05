#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char p[4][2] = {{'R', 'T'}, 
                {'C', 'F'}, 
                {'J', 'M'}, 
                {'A', 'N'}};
int score[4][2] = {{0, 0},
                   {0, 0},
                   {0, 0},
                   {0, 0}};
// survey_len은 배열 survey의 길이입니다.
// choices_len은 배열 choices의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* survey[], size_t survey_len, int choice[], size_t choices_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(sizeof(char) * 5);
    for(int i = 0; i < survey_len; i++){
        if(survey[i][0] == 'R'){
            if(choice[i] < 4)
                score[0][0] += abs(4 - choice[i]);
            else
                score[0][1] += choice[i] - 4;
        }
        else if(survey[i][0] == 'T'){
            if(choice[i] < 4)
                score[0][1] += abs(4 - choice[i]);
            else
                score[0][0] += choice[i] - 4;
        }
        else if(survey[i][0] == 'C'){
            if(choice[i] < 4)
                score[1][0] += abs(4 - choice[i]);
            else
                score[1][1] += choice[i] - 4;
        }
        else if(survey[i][0] == 'F'){
            if(choice[i] < 4)
                score[1][1] += abs(4 - choice[i]);
            else
                score[1][0] += choice[i] - 4;
        }
        else if(survey[i][0] == 'J'){
            if(choice[i] < 4)
                score[2][0] += abs(4 - choice[i]);
            else
                score[2][1] += choice[i] - 4;
        }
        else if(survey[i][0] == 'M'){
            if(choice[i] < 4)
                score[2][1] += abs(4 - choice[i]);
            else
                score[2][0] += choice[i] - 4;
        }
        else if(survey[i][0] == 'A'){
            if(choice[i] < 4)
                score[3][0] += abs(4 - choice[i]);
            else
                score[3][1] += choice[i] - 4;
        }
        else if(survey[i][0] == 'N'){
            if(choice[i] < 4)
                score[3][1] += abs(4 - choice[i]);
            else
                score[3][0] += choice[i] - 4;
        }
    }
    char ch = 0;
    for(int j = 0; j < 4; j++){
        if(score[j][0] >= score[j][1]){
            ch = p[j][0];
            answer[j] = ch;
        }
        else{
            ch = p[j][1];
            answer[j] = ch;
        }
        
    }
    answer[4] = '\0'; //마지막에 널문자 넣기!
    
    return answer;
}
