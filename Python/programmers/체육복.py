#배열을 이용한 방법
def solution(n, lost, reserve):
    answer = 0
    student = [0] * (n+2)
    for i in reserve:
        student[i] += 1
    for i in lost:
        student[i] -= 1
    #이러면 둘다 도난당하고 여분가지고 있는 학생은 알아서 걸러짐
    
    for i in range(1, n+1):
        if student[i] == -1:
            if student[i-1] == 1:
                student[i] = 0
                student[i-1] = 0
            elif student[i+1] == 1:
                student[i] = 0
                student[i+1] = 0
    
    for i in range(1, n+1):
        if student[i] >= 0:
            answer += 1
    return answer


#내가 짠 알고리즘에 set으로 공통인자 제거 -> 100/100
def solution(n, lost, reserve):
    
    lost_only = set(lost) - set(reserve)
    reserve_only = set(reserve) - set(lost)

    answer = n
    lost_len = len(lost_only)
    reserve_len = len(reserve_only)
    list = []
    
    for i in range(n + 2):
        list.append(0)
    
    for i in lost_only:
        list[i] = 1
    
    for i in reserve_only:
        if list[i-1] == 1:
            list[i-1] = 0
        elif list[i+1] == 1:
            list[i+1] = 0
        else:
            continue
            
    for i in list:
        if i == 1:
            answer -= 1
    return answer

#내가 짠 알고리즘 테스트 2개가 실패 뜸 -> 92/100
def solution(n, lost, reserve):
    answer = n
    lost_len = len(lost)
    reserve_len = len(reserve)
    list = []
    
    for i in range(n + 2):
        list.append(0)
    
    for i in lost:
        list[i] = 1
    
    # lost 와 reserve 값이 같은 게 있는 경우 둘다 리스트에서 없애줌
    for idx, i in enumerate(reserve):
        if list[i] == 1:
            list[i] = 0    
            reserve.pop(idx)
    
    for i in reserve:
        if list[i-1] == 1:
            list[i-1] = 0
        elif list[i+1] == 1:
            list[i+1] = 0
        else:
            continue
    for i in list:
        if i == 1:
            answer -= 1
    return answer
    
            
            
# 0 0 0 0 0 만들고
#   1   1.  익덱스에 대입
# for 1 3 5 if i-1 -> i -> i+1 ->
# if lost x -> return , if reserve x -> return 
