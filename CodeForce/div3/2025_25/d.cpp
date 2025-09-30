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



    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<int> a;
        vector<int> b;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c == 'a') a.push_back(i);
            else if (c == 'b') b.push_back(i);
        }
        ll ans_a = (1<<30);
        ll ans_b = (1 << 30);
        if (!a.empty()) {
            ans_a = 0;
            int median_a = a[a.size() / 2];
            int start_a = median_a - (a.size() / 2);
            for (int i = 0; i < a.size(); ++i) {
                ans_a += abs(a[i] - (start_a + i));
            }
        }
        if (!b.empty()) {
            ans_b = 0;
            int median_b = b[b.size() / 2];
            int start_b = median_b - (b.size() / 2);
            for (int i = 0; i < b.size(); ++i) {
                ans_b += abs(b[i] - (start_b + i));
            }
        }

        cout << min(ans_a, ans_b) << endl;

    }

    return 0;
}