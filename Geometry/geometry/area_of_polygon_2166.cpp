// Problem: BOJ 2166

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct Point
{
    ll x, y;
};


void solve() {
    int n; cin >> n;
    // 각 점들이 순서대로 주어지기에 따로 가공할 필요없음
    vector<Point> ps(n);
    for(int i = 0; i < n; i++) cin >> ps[i].x >> ps[i].y;

    double area = 0;
    for(int i = 0; i < n; i++) {
        Point p1 = ps[i];
        Point p2 = ps[(i+1) % n];
        area = area + ((p1.x * p2.y) - (p2.x * p1.y));
    }
    area = abs(0.5 * area);
    printf("%.1f\n", area);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}