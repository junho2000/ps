#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int stack[1000000];

// ingredient_len은 배열 ingredient의 길이입니다.
int solution(int ingredient[], size_t ingredient_len) {
    int answer = 0;
    int size=0;
    for(int i=0;i<ingredient_len;i++){
        stack[size++]=ingredient[i];
        if(stack[size-1]==1){
            while(size>=4){
                if(stack[size-4]==1&&stack[size-3]==2&&stack[size-2]==3&&stack[size-1]==1){
                    answer++;
                    size-=4;
                }
                else break;
            }
        }
    }
    return answer;
}


// #include <stdio.h>
// #include <stdbool.h>
// #include <stdlib.h>
// int stack[1000001] = {0,};
// //1 2 3 1
// // ingredient_len은 배열 ingredient의 길이입니다.
// int solution(int ingredient[], size_t ingredient_len) {
//     int answer = 0;
//     int idx = 0;
//     int len = ingredient_len;
//     while(len >= 4){
//         for(int i = 0; i < ingredient_len; i++){
//             stack[idx] = ingredient[i];
//             if(stack[idx] == 1 && idx >= 3){
//                 if(stack[idx-3] == 1 && stack[idx-2] == 2 && stack[idx-1] == 3){
//                     answer++;
//                     idx-=3;
//                     len-=4;
//                     continue;
//                 }
//             }
//             idx++;
//         }  
//         if(answer == 0) break; // 3+4
//     }
//     return answer;
// }    

//1 2 3 1

//2
//2 1
//2 1 1 
//2 1 1 2
//2 1 1 2 3
//2 1 1 2 3 1
//2 1
//2 1 2
//2 1 2 3
//2 1 2 3 1
//2 
