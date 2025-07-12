// Problem: BOJ 1932

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
    vector<ll> dp(n+1, 0);
    for (int i = 1; i <= n; i++) {
        // i번째 행을 역순으로 갱신
        for (int j = i; j >= 1; j--) {
            ll current_val;
            cin >> current_val;
            
            // j번째 값은, 이전 행의 j-1번째와 j번째 값 중 큰 것과 더해야 함
            // 1차원 dp를 사용하기에 값이 겹치는 것을 방지하기 위해 역순으로 연산진행
            dp[j] = max(dp[j], dp[j-1]) + current_val;
        }
    }
    cout << *max_element(all(dp)) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}