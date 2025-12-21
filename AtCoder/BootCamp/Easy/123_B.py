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
    idx = 0
    m = 11
    arr = []
    time = 0
    for _ in range(5):
        t = int(input())
        arr.append(t)
    for i in range(5):
        if arr[i] % 10 == 0: continue
        if ((arr[i] % 10) < m):
            m = arr[i] % 10
            idx = i
    arr[idx], arr[4] = arr[4], arr[idx]
    for i in arr[:4]:
        time += i
        if (time % 10 != 0):
            time = (time // 10 + 1) * 10
    time += arr[4]
    print(time)

    
    
    

if __name__ == '__main__':
    solve()