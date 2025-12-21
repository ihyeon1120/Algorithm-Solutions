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
    arr = []
    max_idx = -1
    m = -1
    m1 = -1
    for i in range(n):
        t = int(input())
        arr.append(t)
        if (m < t):
            m = t
            max_idx = i
    for i in range(n):
        if (i == max_idx): continue
        m1 = max(m1, arr[i])
    for i in range(n):
        if (i == max_idx): print(m1)
        else: print(m)
    
if __name__ == '__main__':
    solve()