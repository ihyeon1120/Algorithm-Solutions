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
    cnt = [0] * (n+1)
    for _ in range(m):
        a, b = mi()
        cnt[a]+=1
        cnt[b]+=1

    for i in cnt[1:]:
        print(i)

if __name__ == '__main__':
    solve()