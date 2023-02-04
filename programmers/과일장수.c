#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// score_len은 배열 score의 길이입니다.
int solution(int k, int m, int score[], size_t score_len) {
    int answer = 0; 
    int score_info[k+1]; // [1]=3, [2]=2, [3]=2
    for(int j = 0; j < k+1; j++) // 배열 0으로 초기화
        score_info[j] = 0;
    int sum = 0;
    if(score_len/m == 0) return 0; // 이익 발생 x
    for(int i = 0; i < score_len; i++){
        score_info[score[i]]++;
    }
    
    for(int idx = 0; idx < k; idx++){
        sum+=score_info[k-idx];
        while(sum >= m){ // k가 3일 때 6개씩 들어올 수도 있음
            answer += (k-idx)*m;
            sum -= m;
        }
    }
    
    return answer;
}
// 3 3 2 2 1 1 1 -> [1]=3, [2]=2, [3]=2
// 3322 -> 8
// 2 + 2 >= 4 -4 3 

// 4 4 4 4 4 4 2 2 2 2 1 1 -> [1]=2, [2]=4, [4]=6
// 444 444 222 211 -> 12+12+6+3
// 6 >= 3 -3 >= 3 -3 4 >= 3 1 3 >= 3 0
