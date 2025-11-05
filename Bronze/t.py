import sys
input = sys.stdin.readline
a = int(input())
b = int(input())
c = int(input())
d = a * b * c
dp = [0] * 10
while (d > 0):
    t = d % 10
    d = d//10
    dp[t]+= 1
for i in range(10):
    print(dp[i])