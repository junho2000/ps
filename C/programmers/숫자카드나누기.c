#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int arrayA[], size_t arrayA_len, int arrayB[], size_t arrayB_len) {
    int minA = arrayA[0], minB = arrayB[0];
    bool t;
    int num;
    
    for(int i = 1; i < arrayA_len; i++) if(arrayA[i] < minA) minA = arrayA[i];
    for(int i = 1; i < arrayB_len; i++) if(arrayB[i] < minB) minB = arrayB[i];
    
    for(num = minA; num >= 2; num--){
        if(minA % num == 0){
            t = true;
            for(int j = 0; j < arrayA_len && t; j++){
                if(arrayA[j] % num != 0)
                    t = false;
            }
            for(int j = 0; j <arrayB_len && t; j++){
                if(arrayB[j] % num == 0)
                    t = false;
            }
            if(t)
                break;
        }
    }
    // 이때 num의 최솟값 1(답이 없을 때)
    
    for(int i = minB; i > num; i--){
        if(minB % i == 0){
            t = true;
            for(int j = 0; j < arrayB_len && t; j++){
                if(arrayB[j] % i != 0)
                    t = false;
            }
            for(int j = 0; j < arrayA_len && t; j++){
                if(arrayA[j] % i == 0)
                    t = false;
            }
            if(t) return i;
        }
    }

    if(num == 1) return 0;
    else return num;
}
