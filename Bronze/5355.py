t = int(input())
for _ in range(t):
    oper = list(map(str, input().split()))
    n = float(oper[0])
    for op in oper[1:]:
        if op == "@": n *= 3
        elif op == "%": n += 5
        else: n -= 7
    print(f"{n:.2f}") 