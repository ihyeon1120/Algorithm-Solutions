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
    n = int(input())
    heights = li()
    ans = 0
    cur = 0
    cur_ans = 0
    for i in range(n):
        if (cur < heights[i]):
            ans = max(ans, cur_ans)
            cur_ans = 0
        else:
            cur_ans += 1
        cur = heights[i]
    ans = max(ans, cur_ans)
    print(ans)

if __name__ == '__main__':
    solve()