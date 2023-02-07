#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> //strlen, strcpy

//  s	    skip	index	result
// "aukks"	"wbqd"	5	    "happy"

char* solution(const char* s, const char* skip, int index) {

    int len = strlen(s); // s 길이
    int key = 0;
    char* answer = (char*)malloc(sizeof(char)*len); // s의 길이만큼 메모리 할당
    strcpy(answer,s); // answer에 s 대입
    for(int i=0; i<len; i++){ // s 요소 하나하나 접근
        for(int j=0; j<index; j++){ // index만큼 알파벳 넘어가기
            answer[i]++;
            if(answer[i]>'z') // z를 넘으면 다시 a로
                    answer[i]-=26;
            while(true){
                key = 0;
                for(int k=0; k<strlen(skip); k++){ // skip에 있는 요소 하나하나 대조(skip이 순서가 없기 때문에 놓칠 수 있음 -> 계속 대조)
                    if(answer[i] == skip[k]){
                        answer[i]++;
                        if(answer[i]>'z')
                            answer[i]-=26;
                        key = 1;
                    }
                }
                if(key == 0) break; // 바뀐것이 없다면 넘어감
            }
        }
    }
    return answer;
}
