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
    vector<int> bot(H+1, 0), top(H+1, 0);
    for (int i = 0; i < N; ++i) {
        int t; cin >> t;
        if (i % 2 == 0) bot[t]++;
        else top[H - t + 1]++;
    }

    for (int h = H - 1; h >= 1; --h) {
        bot[h] += bot[h+1];
    }
    for (int h = 2; h < H + 1; ++h) {
        top[h] += top[h-1];
    }
    int minBreak = (1 << 30);
    int cnt = 0;
    for (int h = 1; h <= H; ++h) {
        int b =  bot[h] + top[h];
        if (b < minBreak) {
            minBreak = b;
            cnt = 1;
        }
        else if(b == minBreak) cnt++;
    }
    cout << minBreak << " " << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}