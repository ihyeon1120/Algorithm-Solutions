import sys
import math
from collections import deque, Counter
from heapq import heapify, heappush, heappop
from bisect import bisect_left, bisect_right

sys.setrecursionlimit(10**6)

input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    n = int(input())
    adj = [[] for _ in range(n+1)]
    for i in range(1, n+1):
        adj[i].append(int(input()))
    
    q = deque()
    visited = [-1] * (n+1)
    q.append(1)
    visited[1] = 0
    while q:
        cur = q.popleft()
        for next in adj[cur]:
            if (visited[next] != -1): continue
            q.append(next)
            visited[next] = visited[cur] + 1
    print(visited[2])
if __name__ == '__main__':
    solve()