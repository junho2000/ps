#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
//알고리즘에 대해 더 생각해보기

int solution(int storey) {
    int answer = 0;
    int num = storey;
    int temp = 0;
    int temp1 = 0;
    while(num){
        temp = num % 10; // 일의 자리
        temp1 = num % 100; // 십의 자리
        if(temp > 5){
            num += 10 - temp; 
            answer += 10 - temp;
        }
        else if(temp == 5){ // 일의 자리가 5일때 십의 자리 보고 올릴지 말지 골라야함.
            answer += 5; // 빼든 더하든 어짜피 +5
            if(temp1 >= 50) // 십의자리가 5 이상일 경우 그냥 올리는 게 더 좋음.
                num += 10;
                
        }
        else{
            answer += temp;
        }
        num = num / 10;
    }
    return answer;
}