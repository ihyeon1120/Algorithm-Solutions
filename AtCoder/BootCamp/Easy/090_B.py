import sys
import math
from collections import deque, Counter
from heapq import heapify, heappush, heappop
from bisect import bisect_left, bisect_right

sys.setrecursionlimit(10**6)

input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def is_palin(s):
    for i in range((len(s) // 2)):
        if (s[i] != s[len(s) - i - 1]):
            return 0
    return 1
def solve():
    MINN = 10000
    MAXN = 99999 + 1
    arr = [0] * MAXN
    for i in range(MINN, MAXN):
        arr[i] = arr [i-1] + is_palin(str(i))
    a, b = mi()
    print(arr[b] - arr[a-1])
    
if __name__ == '__main__':
    solve()