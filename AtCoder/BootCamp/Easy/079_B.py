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
    lukas = [2, 1]
    for i in range(2, 87):
        lukas.append(lukas[i-1] + lukas[i-2])
    n = int(input())
    print(lukas[n])

if __name__ == '__main__':
    solve()