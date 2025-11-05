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

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<string> v;
    int max_cnt = 0;
    for (int i = 0; i < n - k + 1; ++i) {
        string sub = s.substr(i, k);
        int cnt = 0;
        for (int j = i; j < n - k + 1; ++j){
            string temp = s.substr(j, k);
            if (sub == temp) cnt ++;
        }
        if (cnt > max_cnt) {
            max_cnt = cnt;
            v.clear();
            v.push_back(sub);
        }
        else if (cnt == max_cnt) v.push_back(sub);
    }
    sort(all(v));
    cout << max_cnt << endl;
    for (string i : v) cout << i << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}