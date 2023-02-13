# 문제 접근 방법 1 (roop)
# sort list participant and completion
# and then compare elementwise
# if there are no differ at the end of loop
# answer is participant's last element

def solution(participant, completion):
    participant.sort()
    completion.sort()
    for i in range(len(completion)):
        if participant[i] != completion[i]:
            return participant[i]
        #만약 다 돌고도 없으면 마지막 사람이 안주 못한 것
    return participant.pop()
    
# 문제 접근 방법 2 (hashing)
# in python, you can make a pair, key and value, in dictionary
# sum all participant's hash - sum all completion's hash
# then we can get a key of person who can't complete race

def solution(participant, completion):
    dic = {}
    part_sum = 0
    comp_sum = 0
    for person in participant:
        dic[hash(person)] = person
        part_sum += hash(person)
    
    for person in completion:
        comp_sum += hash(person)
    
    return dic[part_sum - comp_sum]

#문제 접근 방법 3 (counter)
# ["leo", "kiki", "eden"] -> Counter -> {"leo" : 1, "kiki" : 1, "eden" : 1}
# make participant's and competion's Counter and sub
# then remain {"leo":1}
from collections import Counter
def solution(participant, completion):
    
    part_count = Counter(participant)
    comp_count = Counter(completion)
    
    answer = part_count - comp_count
    return list(answer.keys())[0]
