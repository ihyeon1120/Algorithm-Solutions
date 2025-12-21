// Problem: BOJ 20149

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

double get_x(double m1, double s1, double m2, double s2) {
    return  (s2 - s1) / (m1 - m2);
}

void solve() {
    
    double x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    double x3, y3, x4, y4; cin >> x3 >> y3 >> x4 >> y4;
    if (x1 > x2) {
        swap(x1, x2);
        swap(y1, y2);
    }
    if (x3 > x4) {
        swap(x3, x4);
        swap(y3, y4);
    }
    if (x1 == x3 && y1 == y3) {
        cout << 1 << endl;
        cout << x1 << " " << y1 << endl;
        return;
    }
    else if (x1 == x4 && y1 == y4) {
        cout << 1 << endl;
        cout << x1 << " " << y1 << endl;
        return;
    }
    else if (x2 == x3 && y2 == y3) {
        cout << 1 << endl;
        cout << x2 << " " << y2 << endl;
        return;
    }
    else if (x2 == x4 && y2 == y4) {
        cout << 1 << endl;
        cout << x2 << " " << y4 << endl;
        return;
    }
    double m1 = (y2 - y1) / (x2 - x1);
    double m2 = (y4 - y3) / (x4 - x3);
    double s1 = (-m1 * x1) + y1;
    double s2 = (-m2 * x3) + y3;
    if (abs(m1 - m2) <= 1e-9) {
        // 평행하면서 절편이 같을 떄
        if (abs(s2 - s1) <= 1e-9) {
            if ((x3 <= x1 && x1 <= x4) || (x1 <= x3 && x3 <= x2)) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }
        // 평행하면서 절편이 다를 때
        else {
            cout << 0 << endl;
        }
    }
    // 평행하지 않을 때
    else {
        double px = get_x(m1, s1, m2, s2);
        if ((x1 <= px && px <= x2) && (x3 <= px && px <= x4)) {
            double py = m1 * px + s1;
            cout << 1 << endl;
            cout << px << " " << py << endl;
        }
        else {
            cout << 0 << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(17);

    solve();

    return 0;
}