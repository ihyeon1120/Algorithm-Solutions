#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, A, B; 
    cin >> N >> A >> B;
    string s; cin >> s;

    vector<int> pfA(N+1, 0), pfB(N+1, 0);
    for (int i = 0; i < N; ++i) {
        pfA[i+1] = pfA[i] + (s[i] == 'a');
        pfB[i+1] = pfB[i] + (s[i] == 'b');
    }

    ll ans = 0;
    int a_idx = 0, b_idx = 0;

    for (int i = 0; i < N; ++i) {
        // r는 항상 i+1 이상이어야 함
        a_idx = max(a_idx, i + 1);
        b_idx = max(b_idx, i + 1);

        // ind1: cnt_a(i, r) >= A 가 되는 "최초 r"
        while (a_idx <= N && pfA[a_idx] - pfA[i] < A) a_idx++;

        // ind2: cnt_b(i, r) >= B 가 되는 "최초 r"
        while (b_idx <= N && pfB[b_idx] - pfB[i] != B) b_idx++;

        // 가능한 r는 [ind1, ind2-1] → 개수는 max(0, ind2 - ind1)
        ans += max(0, b_idx - a_idx);
    }

    cout << ans << "\n";
}
