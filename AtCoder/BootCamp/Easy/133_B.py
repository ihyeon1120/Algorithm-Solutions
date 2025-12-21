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
    n, d = mi()
    points = [li() for _ in range(n)]
    ans = 0
    for i in range(n):
        for j in range(i + 1, n):
            dist = 0
            for k in range(d):
                dist += (points[i][k] - points[j][k])*(points[i][k] - points[j][k])
            dist = math.sqrt(dist)
            if (dist.is_integer()): ans += 1
    print(ans)

if __name__ == '__main__':
    solve()