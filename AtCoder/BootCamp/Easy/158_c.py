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
    a, b = mi()
    i = 0
    while True:
        i += 1
        if (int(i * 0.08) == a and int(i * 0.1) == b):
            print(i)
            break
        elif (int(i * 0.08) > a or int(i * 0.1) > b): 
            print(-1)
            break

if __name__ == '__main__':
    solve()