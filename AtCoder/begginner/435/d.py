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
    n, m = mi()
    adj = [[] for _ in range(n+1)]
    for _ in range(m):
        a, b = mi()
        adj[b].append(a)
    
    parent = [0 for i in range(n+1)]
    q = int(input())
    def dfs(cur):
        if (parent[cur] == 1): return
        parent[cur] = 1
        for next in adj[cur]:
            if (parent[next] == 1): continue
            dfs(next)
    for _ in range(q):
        t, v = mi()
        if (t == 1):
            dfs(v)
        if (t == 2):
            print("Yes" if parent[v] else "No")
            
if __name__ == '__main__':
    solve()