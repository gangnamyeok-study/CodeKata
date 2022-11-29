from heapq import heappush, heappop

def solution(scoville, K):

    minHeap = []

    for sc in scoville:

      heappush(minHeap, sc)

      

    answer = 0

    while (len(minHeap) > 1):

      if(minHeap[0] >= K):

        return answer

      

      first = minHeap[0]

      heappop(minHeap)

      second = minHeap[0]

      heappop(minHeap)

      heappush(minHeap, first + (second * 2))

      answer += 1

    //pq 크기 1일 때 음식의 스코빌 지수 K이상인지 검사!

    if(minHeap[0] >= K):

        return answer

    return -1
