// Problem: BOJ 3020

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
    int N, H; cin >> N >> H;
    vector<ll> bot(N/2);
    vector<ll> top(N/2);
    for (int i = 0 ; i < N; ++i) {
        int idx = i / 2;
        if(i % 2 == 0) cin >> bot[idx];
        else {
            int t; cin >> t;
            top[idx] = H - t + 1;
        }
    }
    sort(all(bot));
    sort(all(top));
    int breaking = (1 << 30);
    int cnt = 0;
    for (int h = 1; h <= H; ++h) {
        int ind1 = lower_bound(all(bot), h) - bot.begin();
        int ind2 = upper_bound(all(top), h) - top.begin();
        ind1 = N/2 - ind1;
        if (ind1 + ind2 < breaking) {
            cnt = 1;
            breaking = ind1 + ind2;
        }
        else if (ind1 + ind2 == breaking) cnt ++;
    }

    cout << breaking << " " << cnt << endl;


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}