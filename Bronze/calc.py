import math
s1, s2, n1, n2 = map(float, input().split())
ss1 = s1 * s1
ss2 = s2 * s2
ssn1 = ss1 / n1
ssn2 = ss2 / n2
df = math.pow(ssn1 + ssn2, 2) / ((math.pow(ssn1, 2) / (n1-1)) + (math.pow(ssn2, 2) / (n2 - 1)))
print(int(df))