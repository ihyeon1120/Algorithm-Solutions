#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Fenwick {
    int n;
    vector<ll> f;
    Fenwick(int n) : n(n), f(n+1, 0) {}
    void update(int i, ll v) {
        for (; i <= n; i += i & -i) f[i] += v;
    }
    ll query(int i) {
        ll s = 0;
        for (; i > 0; i -= i & -i) s += f[i];
        return s;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    const int MAXA = 500000;
    Fenwick cnt(MAXA+5), sumv(MAXA+5);

    vector<ll> A(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        cnt.update(A[i]+1, 1);
        sumv.update(A[i]+1, A[i]);
    }

    while (Q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int x;
            ll y;
            cin >> x >> y;
            ll oldv = A[x];

            cnt.update(oldv+1, -1);
            sumv.update(oldv+1, -oldv);

            A[x] = y;

            cnt.update(y+1, 1);
            sumv.update(y+1, y);
        }
        else {
            ll l, r;
            cin >> l >> r;

            if (l > r) {
                cout << l * N << "\n";
                continue;
            }

            // count of Ai < l
            ll count_lt_l = cnt.query(l);

            // count of Ai <= r
            ll count_le_r = cnt.query(r+1);

            ll count_gt_r = N - count_le_r;

            ll sum_lt_l = sumv.query(l);
            ll sum_le_r = sumv.query(r+1);

            ll sum_mid = sum_le_r - sum_lt_l;

            ll ans = count_lt_l * l + sum_mid + count_gt_r * r;

            cout << ans << "\n";
        }
    }
}
