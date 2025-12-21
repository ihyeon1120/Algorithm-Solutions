// Problem: BOJ 21758

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve() {
    int n; cin >> n;
    vector<int> honey(n);
    vector<int> honey_rev(n);
    vector<ll> pf(n+1, 0);
    vector<ll> pf_rev(n+1, 0);
    int temp = 0;
    int idx = 0;
    for (int i = 0; i < n; ++i) {
        int t; cin >> t;
        if (t > temp) {
            temp = t;
            idx = i;
        }
        honey[i] = t;
        honey_rev[n-1-i] = t;
        pf[i+1] = pf[i] + t;
    }
    for (int i = 0; i < n; ++ i) {
        pf_rev[i+1] = pf_rev[i] + honey_rev[i];
    }
    /*
        탐색 해야할 것
        1. p1, honey, p2 순으로 되어 있을 때의 값은 honey의 최댓값에 꿀통을 넣으면 최대 (p1, p2는 양 끝에 위치)
        2. p1, p2, honey 순으로 되어 있을 때 p1은 항상 왼쪽에 있고 p2가 돌아다니는데 pf[i] + honey[i-1]값의 최소를 구하기
        3. honey를 반대로 돌리고 2번 확인
    */
    ll m = pf[n-1] - pf[idx] + pf[idx+1] - pf[1];
    for (int i = 2; i < n; ++i) {
        m = max(m, pf[n] - pf[1] + pf[n] - pf[i] - honey[i-1]);
        m = max(m, pf_rev[n] - pf_rev[1] + pf_rev[n] - pf_rev[i] - honey_rev[i-1]);
    }
    cout << m << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}