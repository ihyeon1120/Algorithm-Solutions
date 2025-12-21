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
    n, q = mi()
    diff = [1 for _ in range(n+2)]
    adding = 0
    for _ in range(q):
        i, x = mi()
        adding += x
        diff[i] += x
        if diff[i+1] - x > 0:
            diff[i+1] -= x
        else:
            diff[i+1] = 1
    prev = 0
    arr = []
    for i in diff[1:n+1]:
        arr.append(prev + i)
        prev = prev + i
    print(sum(arr) - adding)
        
    

if __name__ == '__main__':
    solve()