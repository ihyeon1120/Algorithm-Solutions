import math

A, B, C = map(int, input().split())

res1 = A * B / C
res2 = A / B * C

print(math.trunc(max(res1, res2)))