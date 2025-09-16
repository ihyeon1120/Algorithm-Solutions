import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    a, b = map(int,input().split())
    if (b % 2 == 0): print(0)
    else: print(a)