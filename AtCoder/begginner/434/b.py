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
    cnt = [[] for _ in range(m+1)]
    for _ in range(n):
        a, b = mi()
        cnt[a].append(b)
    for i in range(1, m+1):
        print(sum(cnt[i]) / len(cnt[i]))
    
if __name__ == '__main__':
    solve()