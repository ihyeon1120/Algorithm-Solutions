// Problem: BOJ 

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool cmp(pii a, pii b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

ll ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (ll)(x2 - x1)*(y3 - y1) - (y2 - y1)*(x3 - x1);
}


/*
1.x, y좌표를 오름차순 정렬
2. lower은 정방향으로 탐색 시작
    2.1 lower에 2개 이상, 추가된 한 점이 시계방향으로 회전하거 일직선에 놓여있는 경우에 lower.pop()
    2.2 lower에 값 추가
3. upper은 역방향 탐색 이후 lower과 로직 동일
4. lower과 upper가 겹치는 부분 제거
*/ 
void monotone_chain() {
    int n; cin >> n;
    vector<pii> pos(n);
    for(int i = 0; i < n; i++)
    {
        int x, y; cin >> x >> y;
        pos[i] = {x, y};
    }
    sort(all(pos), cmp);
    vector<int> upper;
    vector<int> lower;

    for (int i = 0; i < n; i++) {
        // --- 아래쪽 껍질 로직 ---
        while(sz(lower) >= 2 && 
              ccw(pos[lower[sz(lower) - 2]].first, pos[lower[sz(lower) - 2]].second,
                  pos[lower.back()].first, pos[lower.back()].second,
                  pos[i].first, pos[i].second) <= 0) {
            lower.pop_back();
        }
        // 끝점 추가
        lower.push_back(i);

        // --- 위쪽 껍질 로직 ---
        int idx = n - 1 - i; // 역순 인덱스
        while(sz(upper) >= 2 &&
              ccw(pos[upper[sz(upper) - 2]].first, pos[upper[sz(upper) - 2]].second,
                  pos[upper.back()].first, pos[upper.back()].second,
                  pos[idx].first, pos[idx].second) <= 0) {
            upper.pop_back();
        }
        // 끝점 추가
        upper.push_back(idx);
    }

    lower.pop_back();
    upper.pop_back();

    cout << sz(lower) + sz(upper) << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    monotone_chain();

    return 0;
}