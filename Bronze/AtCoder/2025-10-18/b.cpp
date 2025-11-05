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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k; cin >> n >> k;
    string s; cin >> s;
    int ans = -1;
    vector<string> ans_vec;
    for (int i = 0; i <= n - k; ++i) {
        string sub = s.substr(i, k);
        int sub_n = 0;
        for (int j = i; j <= n - k; ++j) {
            string temp = s.substr(j, k);
            if (sub == temp) {
                sub_n++;
            }
        }
        if (sub_n > ans) {
            ans_vec.clear();
            ans_vec.push_back(sub);
            ans = sub_n;
        }
        else if (sub_n == ans) {
            ans_vec.push_back(sub);
        }
    }

    sort(all(ans_vec));
    cout << ans << endl;
    for (string s : ans_vec) cout << s << " ";

    return 0;
}