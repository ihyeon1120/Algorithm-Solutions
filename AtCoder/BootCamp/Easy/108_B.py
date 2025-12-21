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
    x1, y1, x2, y2 = mi()
    diff_x = x2 - x1
    diff_y = y2 - y1
    print(f"{x2 - diff_y} {y2 + diff_x}", end=" ")
    print(f"{x1 - diff_y} {y1 + diff_x}")

if __name__ == '__main__':
    solve()