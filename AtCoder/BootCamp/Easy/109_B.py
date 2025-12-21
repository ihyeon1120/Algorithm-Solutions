import sys
import math
from collections import deque, Counter, defaultdict
from heapq import heapify, heappush, heappop
from bisect import bisect_left, bisect_right

sys.setrecursionlimit(10**6)

input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    n = int(input())
    d = defaultdict(int)
    prev = ""
    flag = True
    words = [input().strip() for _ in range(n)]
    for s in words:
        if d[s] != 0: 
            flag = False
            break
        if prev != "":
            if (prev[-1] != s[0]):
                flag = False
                break
        prev = s
        d[s] += 1
    
    print("Yes" if flag else "No")




if __name__ == '__main__':
    solve()