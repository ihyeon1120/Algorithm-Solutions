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

bool is_palin(const vector<int> &a) {
    int l = 0;
    int r = sz(a) - 1;
    while (l < r) {
        if (a[l] != a[r]) return false;
        l++;
        r--;
    }
    return true;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        bool is_p = false;
        string s;
        cin >> s;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) arr[i] = s[i] - '0';

        for (int l = 0; l < n && !is_p; ++l) {
            for (int i = 0; i < n - l; ++i ) {
                bool is_dec = false;
                vector<int> p = vector<int>(arr.begin() + i, arr.begin() + i + l + 1);
                vector<int> t;
                for (int j = 0; j < n; ++j) {
                    if (i <= j && j <= i + l) continue;
                    t.push_back(arr[j]);
                }
                if (sz(p) > 1) {
                    for (int a = 1; a < sz(p); ++a) {
                        if (p[a-1] > p[a]) {
                            is_dec = true;
                            break;
                        }
                    }

                }
                if (!is_dec) {
                    if (is_palin(t)) {
                        cout << sz(p) << endl;
                        for (int a = i; a < i + l + 1; ++a) cout << a + 1 << " ";
                        cout << endl;
                        is_p = true;
                        break;
                    }
                }
            }
        }
        
    }

    return 0;
}