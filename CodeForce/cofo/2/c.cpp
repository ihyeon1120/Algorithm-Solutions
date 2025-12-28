#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

// erase -> k번 쓰레기들을 지우기
/*
    split -> 제한 없이 숫자 분해 가능
    4 1
    1 5 7 25 
    에서 7을 분해하는 것은 의미가 없음
    1 5 16 25
    에서 16도 분해할 수 없음 5 5 6
    1 5 15 25
    에서 15를 굳이 분해할 필요가 없음
    1 5 21 25
    에서 21을 5 6 10으로 분해 가능 26분해 -> 5 6 15
    -> 분해할 수 있는 수는 4 * GCD 이상은 되어야지 분해하는데 의미가 있다. > 분해하면 g를 만들 수 있다.
    5 x y로 그렇다면 모든 수를 만들 수 있나 
    1. y >= 10 && y % 5 == 0
    2. 5 <= x <= y
    5 x 10 -> 20, 21, 22, 23, 24, 25
    5 x 15 -> 25 26 ... 35
    5 x 20 -> 30 ... 45
    a x 2a -> 4a ... 5a
    a x 3a -> 5a ... 7a
    a x 4a -> 6a ... 9a => 모든 수를 만들 수 있음
*/

const int MAXN = 200005;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    vector<int> cnt(n+1, 0);
    vector<int> prefix(n+1, 0);
    for (int i = 0; i < n; ++i) {
        int t; cin >> t;
        arr[i] = t;
        cnt[t]++;
    }
    // i보다 작은 수의 개수를 저장
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i-1] + cnt[i];
    }

    for (int g = n; g > 0; g--) {
        int in = 0;
        int out = 0;
        // 4g 이상은 볼 필요가 없음 -> 삭제할 필요가 없음
        // 4g - 1에서 삭제해야할 것이 k개를 넘으면 안됌
        // 삭제해야할 것은 4g - 1범위 내에서 g의 배수를 뺀 나머지
        int limit = min(n, 4 * g - 1);
        int total = prefix[limit];

        for (int i = 1; i * g <= limit; ++i) {
            in += cnt[i * g];
        }
        out = total - in;
        if (out <= k) {
            cout << g << endl;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc; cin >> tc;
    while(tc--) solve();

    return 0;
}