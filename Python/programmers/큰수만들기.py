def solution(priorities, location):
    printer = [(i, key) for i, key in enumerate(priorities)]
    turn = 0
    while printer:
        key = printer.pop(0)
        if any(key[1] < other_key[1] for other_key in printer):
            printer.append(key)
    
    print(printer)
    
solution([2, 1, 3, 2], 2)