// Problem: BOJ 9935

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

    vector<char> ans;
    string s, target; cin >> s >> target;
    int target_size = sz(target);
    bool flag = false;
    for (char c : s) {
        ans.push_back(c);
        if (sz(ans) < target_size) continue;
        for (int i = 0; i < target_size; ++i) {
            int idx = i + sz(ans) - target_size;
            if (ans[idx] != target[i]) {
                flag = false;
                break;
            }
            flag = true;
        }
        if (flag) {
            for (int i = 0; i < target_size; ++i) {
                ans.pop_back();
            }
        }
    }
    if (sz(ans) == 0) cout << "FRULA" << endl;
    for (char c : ans) cout << c << "";
    return 0;
}