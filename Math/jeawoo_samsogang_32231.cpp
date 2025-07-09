// Problem: BOJ 32231

/*
조건1: (x, y)에서의 물의 밀도는 1/y
조건2: 밀도가 p인 지점에서의 속력은 1/p -> 속력은 y의 좌표값
조건3: y는 0이 아닌 실수
아이디어: 최소시간 -> 최대 속력 -> y가 커질 수록 속력도 커짐 -> 최대한 위에서 놀다가 밀도차이에 의한 속도 공식 (snell 법칙) 적용
snell 법칙: n1*sin(theta1) = n2*sin(theta2) = K(상수)
굴절률 n = c / v = c / y
sin(theta) = K / y
*/

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct Point {
    double x, y;
};

Point get_center(Point p1, Point p2) {
    Point c;
    if (p1.x == p2.x) {
        c.x = p1.x;
    } else {
        c.x = (p1.x*p1.x - p2.x*p2.x + p1.y*p1.y - p2.y*p2.y) / (2 * (p1.x - p2.x));
    }
    c.y = 0;
    return c;
}


void solve() {
    int n; cin >> n;
    while (n--) {
        Point p1, p2; cin >> p1.x >> p1.y >> p2.x >> p2.y;
        double ans = 0.0;

        if (p1.x == p2.x) { 
            // 경우 2: x좌표가 같을 때 (수직 경로)
            ans = abs(log(p2.y) - log(p1.y));
        } 
        else {
            // 경우 1: x좌표가 다를 때 (원의 호 경로)
            Point c = get_center(p1, p2);
            double theta1 = atan2(p1.y, p1.x - c.x);
            double theta2 = atan2(p2.y, p2.x - c.x);
            ans = abs(log(abs(tan(theta2/2.0))) - log(abs(tan(theta1/2.0))));
        }
        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed;
    cout.precision(6);
    solve();

    return 0;
}