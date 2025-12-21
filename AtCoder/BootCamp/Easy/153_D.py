import sys
import math
from collections import deque, Counter
from heapq import heapify, heappush, heappop
from bisect import bisect_left, bisect_right

sys.setrecursionlimit(10**6)

input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def get_2bit(H) -> int:
    i = 0;
    while ((1 << i) <= H):
        i += 1
    return (1 << (i-1))

def solve():
    H = int(input())
    close_2bit = get_2bit(H)
    i = 0
    ans = 1
    while((1 << i) != close_2bit):
        i += 1
        ans = 2*ans + 1

    print(ans)
if __name__ == '__main__':
    solve()