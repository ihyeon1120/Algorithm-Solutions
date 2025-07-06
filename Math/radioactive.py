import math
import sys

input = sys.stdin.readline


N = 30000

EPS = 1e-9
x_start = -10.0
x_end = 10.0

def compute_ypp(x, y, yp, C):
    yp_sq_plus_1 = yp**2 + 1
    y_minus_C_minus_ypx = y - C - yp * x
    numerator = -2 * yp_sq_plus_1 * y_minus_C_minus_ypx
    d_term = (y - C)**2 + x**2
    denominator = d_term * (d_term + 1)
    if denominator == 0:
        return 0.0
    return numerator / denominator

def rk4(yp0, A, B, C):

    h = (x_end - x_start) / N
    x = x_start
    y = A
    yp = yp0
    for _ in range(N):
        k1 = h * yp; l1 = h * compute_ypp(x, y, yp, C)
        k2 = h * (yp + 0.5 * l1); l2 = h * compute_ypp(x + 0.5 * h, y + 0.5 * k1, yp + 0.5 * l1, C)
        k3 = h * (yp + 0.5 * l2); l3 = h * compute_ypp(x + 0.5 * h, y + 0.5 * k2, yp + 0.5 * l2, C)
        k4 = h * (yp + l3); l4 = h * compute_ypp(x + h, y + k3, yp + l3, C)
        y += (k1 + 2*k2 + 2*k3 + k4) / 6
        yp += (l1 + 2*l2 + 2*l3 + l4) / 6
        x += h
    return y

def find_initial_slope(lo, hi, A_rel, B_rel):
    for _ in range(100):
        mid = (lo + hi) / 2
        y_end = rk4(mid, A_rel, B_rel, 0.0)
        if abs(y_end - B_rel) < EPS:
            return mid
        if y_end > B_rel:
            hi = mid
        else:
            lo = mid
    return (lo + hi) / 2

def integrate_path(yp0, A_rel):
    h = (x_end - x_start) / N
    path = []
    x = x_start
    y = A_rel
    yp = yp0
    for i in range(N + 1):
        path.append((x, y))
        if i == N: break
        k1 = h * yp; l1 = h * compute_ypp(x, y, yp, 0.0)
        k2 = h * (yp + 0.5 * l1); l2 = h * compute_ypp(x + 0.5 * h, y + 0.5 * k1, yp + 0.5 * l1, 0.0)
        k3 = h * (yp + 0.5 * l2); l3 = h * compute_ypp(x + 0.5 * h, y + 0.5 * k2, yp + 0.5 * l2, 0.0)
        k4 = h * (yp + l3); l4 = h * compute_ypp(x + h, y + k3, yp + l3, 0.0)
        y += (k1 + 2*k2 + 2*k3 + k4) / 6
        yp += (l1 + 2*l2 + 2*l3 + l4) / 6
        x += h
    return path

def compute_total_radiation(path):
    total = 0.0
    for i in range(1, len(path)):
        x1, y1 = path[i - 1]
        x2, y2 = path[i]
        ds = math.hypot(x2 - x1, y2 - y1)
        xm = (x1 + x2) / 2
        ym = (y1 + y2) / 2
        d_sq = xm**2 + ym**2
        if d_sq < 1e-9: rate = 1.0
        else: rate = 1.0 + 1.0 / d_sq
        total += rate * ds
    return total

    
T = int(input())
for i in range(1, T + 1):
    _, A, B = map(float, input().split())
    C = float(input())
    A_rel = A - C
    B_rel = B - C

    split_point = (0 - A_rel) / (0 - x_start)

    # (섬보다 낮은 각도)
    slope1 = find_initial_slope(-100.0, split_point, A_rel, B_rel)
    path1 = integrate_path(slope1, A_rel)
    radiation1 = compute_total_radiation(path1)

    # (섬보다 높은 각도)
    slope2 = find_initial_slope(split_point, 100.0, A_rel, B_rel)
    path2 = integrate_path(slope2, A_rel)
    radiation2 = compute_total_radiation(path2)
        
    min_radiation = min(radiation1, radiation2)
        
    print(f"Case #{i}: {min_radiation:.2f}")