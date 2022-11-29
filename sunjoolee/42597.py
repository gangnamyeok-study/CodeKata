from queue import Queue

def solution(priorities, location):
    sortedPriorities = list(priorities)
    sortedPriorities.sort()
    
    q = Queue()
    for loc in range(0,len(priorities)):
        q.put(loc)
    
    answer = 0
    while (not q.empty()):
        curloc = q.get(0)
        
        if(priorities[curloc] < sortedPriorities[-1]):
            q.put(curloc)
        else:
            sortedPriorities.pop()
            answer+=1
            if(curloc == location): 
                break
    return answer
