#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// food_len은 배열 food의 길이입니다.
char* solution(int food[], size_t food_len) {
    int ans_len = 1;
    int idx = 0;
    for(int k = 1; k < food_len; k++){
        if(food[k] < 2)
            continue;
        ans_len += food[k] / 2 * 2;
    }
    char* answer = (char*)malloc(sizeof(char)*(ans_len+1));
    for(int i = 1; i < food_len; i++){
        if(food[i] < 2)
            continue;
        int l = food[i] / 2;
        for(int j = 0; j < l; j++){
            answer[idx] = '0'+ i;
            answer[ans_len-idx-1] = '0'+i;
            idx++;
        }
    }
    answer[ans_len / 2] = '0';
    answer[ans_len] = '\0'; //문자열 마지막에 널문자 넣기..!!
    return answer;
}

// 구현

// #include <stdio.h>
// #include <math.h>
// #include <stdbool.h>

// int main()
// {
//     int ans_len = 1;
//     int idx = 0;
//     int food[] = {1, 3, 4, 6};
//     int food_len = sizeof(food)/sizeof(int);
//     for(int k = 1; k < food_len; k++){
//         if(food[k] < 2)
//             continue;
//         ans_len += food[k] / 2 * 2;
//     }
//     char* answer = (char*)malloc(sizeof(char)*ans_len);
//     for(int i = 1; i < food_len; i++){
//         if(food[i] < 2)
//             continue;
//         int l = food[i] / 2;
//         for(int j = 0; j < l; j++){
//             answer[idx] = i;
//             answer[ans_len-idx-1] = i;
//             idx++;
//         }
//         // 0 1 2 3 4 5 6 7 8
//             // 1             1
//     }
//         answer[ans_len / 2] = 0;
//     for(int a = 0; a<ans_len; a++){
//         printf("%d ", answer[a]);
//     }
//     free(answer);
// }