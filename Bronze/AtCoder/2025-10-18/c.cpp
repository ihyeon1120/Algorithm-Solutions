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

    // 좋은 괄호이려면 sum = 0, 누적합이 0 이상
    int sum = 0;
    int invalidCount = 0;
    string s = "";
    int t; cin >> t;
    while (t--) {
        int type; cin >> type;
        if (type == 1) {
            char c; cin >> c;
            s.push_back(c);
            sum += (c == '(') ? 1 : -1;
            invalidCount += sum == -1;
        }
        else {
            char c = s.back(); s.pop_back();
            invalidCount -= sum == -1;
            sum -= c == '(' ? +1 : -1;
        }
        if(invalidCount == 0 && sum == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}