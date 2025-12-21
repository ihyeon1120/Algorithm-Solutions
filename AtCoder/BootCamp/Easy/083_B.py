import sys
import math
from collections import deque, Counter
from heapq import heapify, heappush, heappop
from bisect import bisect_left, bisect_right

sys.setrecursionlimit(10**6)

input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def get_digits_sum(n):
    ret = 0
    while (n > 0):
        ret += n % 10
        n //= 10
    return ret

def solve():
    n, a, b = mi()
    ans = 0
    for i in range(1, n+1):
        s = get_digits_sum(i)
        if (s < a or s > b): continue
        ans += i
    print(ans)
if __name__ == '__main__':
    solve()