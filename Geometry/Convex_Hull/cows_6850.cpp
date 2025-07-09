// Problem: BOJ 6850

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
    int x, y;
};

Point pivot;

ll distSq(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.x - p2.x);
}

ll ccw(Point p1, Point p2, Point p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

bool cmp(Point p1, Point p2) {
    int k = ccw(pivot, p1, p2);
    if (k == 0) return distSq(pivot, p1) < distSq(pivot, p2);
    return k > 0;
}

ll get_area(const vector<Point>& hull) {
    int n = sz(hull);
    double area = 0;
    for(int i = 0; i < n; i++) {
        Point p1 = hull[i];
        Point p2 = hull[(i+1) % n];
        area = area + ((p1.x * p2.y) - (p2.x * p1.y));
    }
    return area / 2;
}

void solve() {
    int n; cin >> n;
    vector<Point> points(n);
    for(int i = 0; i < n; i++) cin >> points[i].x >> points[i].y;

    int idx = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].y < points[idx].y ||
            (points[i].y == points[idx].y && points[i].x < points[idx].x)) {
                idx = i;
            }
    }
    swap(points[0], points[idx]);
    pivot = points[0];

    sort(points.begin() + 1, points.end(), cmp);
    vector<Point> hull;
    // graham scan
    for(int i = 0; i < n; i ++) {
        while(hull.size() >= 2) {
            Point p2 = hull.back(); hull.pop_back();
            Point p1 = hull.back();
            // 반시계 방향
            if (ccw(p1, p2, points[i]) > 0) {
                hull.push_back(p2);
                break;
            }
        }
        hull.push_back(points[i]);
    }

    ll area = get_area(hull);
    cout << area / 50 << endl;
}   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}