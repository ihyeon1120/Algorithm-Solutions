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

ll DP[55]; 


ll calOne(ll N) {
    ll count = N & 1;     // 최하위 비트 (1이면 +1)
    int size = (int)(log2(N));

    for (int i = size; i > 0; --i) {
        if ((N & (1LL << i)) != 0LL) {
            count += DP[i - 1] + (N - (1LL << i) + 1);
            N -= (1LL << i); // 비트 이동
        }
    }
    return count;
}

// DP[i] = DP[i-1]*2 + 2^i 계산
void setDP() {
    DP[0] = 1;
    for (int i = 1; i < 55; ++i)
        DP[i] = (DP[i - 1] << 1) + (1LL << i);
}

void solve() {
    setDP();
    ll A, B; cin >> A >> B;
    cout << calOne(B) - calOne(A-1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}