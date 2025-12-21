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
    s = input().strip()
    start_black_cnt = 0
    start_white_cnt = 0
    for i in range(len(s)):
        if (i % 2 == 0):
            if s[i] == '0': start_white_cnt += 1
            else: start_black_cnt += 1
        else :
            if s[i] == '0': start_black_cnt += 1
            else: start_white_cnt += 1
    print(min(start_black_cnt, start_white_cnt))
if __name__ == '__main__':
    solve()