// Problem: BOJ 1708

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct Point{
    ll x, y;
};

Point pivot;

ll ccw(Point p1, Point p2, Point p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

ll dist(Point p1, Point p2) {
    return (p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y);
}

bool cmp(Point p1, Point p2) {
    ll k = ccw(pivot, p1, p2);

    if (k == 0) { // 일직선상에 있다면
        // 기준점으로부터 거리가 가까운 순으로 정렬
        return dist(pivot, p1) < dist(pivot, p2);
    }
    // 반시계 방향(좌회전)에 있는 점이 우선순위가 높음
    return k > 0;
} 



void graham_scan(){
    
    int n; cin >> n;
    vector<Point> points(n);
    for(int i = 0; i < n; i++) cin >> points[i].x >> points[i].y;
    int pivot_idx = 0;
    // y, x가 가장 작은 피봇의 인덱스 찾기
    for (int i = 1; i < n; i++) {
        if (points[i].y < points[pivot_idx].y ||
            (points[i].y == points[pivot_idx].y && points[i].x < points[pivot_idx].x)) {
                pivot_idx = i;
            }
    }

    swap(points[0], points[pivot_idx]);
    pivot = points[0];

    sort(points.begin() + 1, points.end(), cmp);
    vector<Point> hull;
    for (int i = 0; i < n; i++) {
        // 다음 것이 반시계 방향이라면 hull에 추가, 아니라면 hull 마지막걸 삭제 후 hull에 추가
        while(sz(hull) >= 2) {
            Point p2 = hull.back(); hull.pop_back();
            Point p1 = hull.back();
            if (ccw(p1, p2, points[i]) > 0) {
                hull.push_back(p2);
                break;
            }
        }
        hull.push_back(points[i]);
    }
    cout << hull.size() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    graham_scan();

    return 0;
}