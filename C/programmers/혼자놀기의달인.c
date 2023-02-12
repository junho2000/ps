//checked와 group 그리고 card의 인덱스 갖고 노는 것이 어려워서 좀 고전함
//그럴 땐 차근차근 노트에 써보자

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int static compare(const void* front, const void* rear){
    if(*(int*)front < *(int*)rear)
        return 1;
    else if(*(int*)front > *(int*)rear)
        return -1;
    else 
        return 0;
}

bool checked[101] = {false}; // 방문했던 노드인지 확인
int group[101] = {0}; // 그룹 길이 저장 -> 정렬 예정


int solution(int cards[], size_t cards_len) {
    int idx = 0; // 그룹 인덱스
    int s;
    int cnt;
    for(int i = 0; i < cards_len; i++){
        if(checked[i])
            continue;
        
        s = i;
        checked[s] = true;
        cnt = 1;
        while(true){
            if(!checked[cards[s]-1]){
                checked[cards[s]-1] = true;
                s = cards[s] - 1;
                cnt++;
            }
            else
                break;
        }
        group[idx++] = cnt;
    }
    qsort(group,101,sizeof(int),compare);
    return group[0] * group[1];
}