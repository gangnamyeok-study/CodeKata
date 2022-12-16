from collections import deque


def solution(bridge_length, weight, truck_weights):
    answer = 0
    truck_weights = deque(truck_weights)
    ongoing = deque()
    while truck_weights or ongoing:
        for o in ongoing:
            o[1] += 1
        if ongoing and ongoing[0][1] == bridge_length:
            ongoing.popleft()
        if truck_weights:
            if len(ongoing) == 0 or sum([o[0] for o in ongoing]) + truck_weights[0] <= weight:
                ongoing.append([truck_weights.popleft(), 0])
        answer += 1
    return answer
