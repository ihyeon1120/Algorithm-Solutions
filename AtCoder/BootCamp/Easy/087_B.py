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
    a = int(input())
    b = int(input())
    c = int(input())
    x = int(input())
    ans = 0
    for i in range(a+1):
        for j in range(b+1):
            for k in range(c+1):
                if (500 * i + 100 * j + 50 * k == x):
                    ans += 1
    print(ans)
if __name__ == '__main__':
    solve()