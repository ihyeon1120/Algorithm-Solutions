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
    arr = li()
    flag = True
    i = 0
    while flag:
        for k in range(len(arr)):
            if (arr[k] % 2 != 0):
                flag = False
                break
            else:
                arr[k] = arr[k] / 2
        i += 1
    print(i-1)

if __name__ == '__main__':
    solve()