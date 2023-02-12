#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int answer = 1;
    int s_len = strlen(s);
    int cnt = 0;
    char c;
    c = s[0];
    cnt++;
    for(int i = 1; i < s_len; i++){
        if(cnt == 0){
            c = s[i];
            answer++;
        }
        // 처음보는 문자 나왔을 때 cnt +1, 다음 문자가 
        if(s[i] == c)
            cnt++;
        else
            cnt--;
    }
    return answer;
}