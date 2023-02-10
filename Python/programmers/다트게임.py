#다른 사람 풀이 
#숫자는 무시하고 연산자만 처리
#대신 숫자는 시작 인덱스만 관리
#더 파이써닉함
def solution(dartResult):
    scores = []
    start_idx = 0
    power = {'S': 1, 'D': 2, 'T': 3}
    for i in range(len(dartResult)):
        op = dartResult[i]
        if op in power:
            scores.append(int(dartResult[start_idx:i])**power[op])
        elif op == '*':
            scores[-2:] = [x * 2 for x in scores[-2:]]
        elif op == '#':
            scores[-1] = -scores[-1]
        
        if not op.isnumeric():
            start_idx = i + 1
    return sum(scores)


#내가 푼 풀이
def solution(dartResult):
    answer = 0
    score_list = [0]
    idx = 0
    temp = 0
    
    score = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
    bonus = {'S': 1, 'D': 2, 'T': 3}
    option = {'*': 2, '#': -1}
    
    for i in range(len(dartResult)):
        if dartResult[i] in score:
            if i >= 1 and dartResult[i] == '0' and dartResult[i-1] == '1':
                temp = 10
            else:
                temp = int(dartResult[i])
                
        elif dartResult[i] in bonus:
            temp **= bonus[dartResult[i]]
            idx += 1
            score_list.append(temp)
            
        elif dartResult[i] in option:
            if dartResult[i] == '*':
                score_list[idx-1] *= option[dartResult[i]]
                score_list[idx] *= option[dartResult[i]]
            else:
                score_list[idx] *= option[dartResult[i]]
            
    return sum(score_list)

print(solution('1S2D*3T'))