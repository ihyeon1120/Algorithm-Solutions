n = int(input())
a = 0
b = 0
for _ in range(n):
    s = input()
    if abs(a - b) == 2: continue
    if (s == 'D'): a += 1
    else: b += 1

print(str(a) + ":" + str(b))