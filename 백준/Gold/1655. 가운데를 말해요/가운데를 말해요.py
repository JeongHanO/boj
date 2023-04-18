import sys
import heapq

minHeap = []
maxHeap = []

n = int(sys.stdin.readline())

for _ in range(n):
    a = int(sys.stdin.readline())
    if len(minHeap) == len(maxHeap):
        heapq.heappush(maxHeap, -a)
    else:
        heapq.heappush(minHeap, a)

    if minHeap and -maxHeap[0] > minHeap[0]:
        minV = heapq.heappop(minHeap)
        maxV = heapq.heappop(maxHeap)

        heapq.heappush(minHeap,-maxV)
        heapq.heappush(maxHeap, -minV)
    print(-maxHeap[0])
    
