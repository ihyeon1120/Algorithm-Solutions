import sys
from collections import deque
input = sys.stdin.readline

dq = deque()

n = int(input())
for _ in range(n):
    s = list(map(str, input().split()))
    comm = s[0]
    if (s[0] == "push_front"):
        dq.appendleft(int(s[1]))
    elif (s[0] == "push_back"):
        dq.append(int(s[1]))
    elif (s[0] == "pop_front"):
        if (len(dq) == 0): print(-1)
        else: print(dq.popleft())
    elif (s[0] == "pop_back"):
        if (len(dq) == 0): print(-1)
        else: print(dq.pop())
    elif (s[0] == "size"):
        print(len(dq))
    elif (s[0] == "empty"):
        print(int(len(dq) == 0))
    elif (s[0] == "front"):
        if (len(dq) == 0): print(-1)
        else: print(dq[0])
    elif (s[0] == "back"):
        if (len(dq) == 0): print(-1)
        else: print(dq[-1])