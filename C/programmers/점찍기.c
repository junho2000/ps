#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// k와 d의 범위가 1000000이므로 long long을 써야함
bool is_in(long long x, long long y, long long d){
    if(x*x + y*y <= d*d){
        return true;
    }
    else
        return false;
}

long long solution(int k, int d) {
    long long answer = 0;
    int N = d/k;
    int idx = 0;
    int j = N;
    for(int i = 0; i <= N; i++){
        for(; j >= 0; j--){ // 그냥 j = N하면 계속 N으로 돌아가니까 어짜피 돌아갈 필요없으니 j를 업데이트 하지 않는다 -> 시간초과 해결
            if(is_in(k*i, k*j, d)){
                answer += j + 1;
                break;
            }
        }
    }
    
    return answer;
}