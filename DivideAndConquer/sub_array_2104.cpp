// Problem: BOJ 2104

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 100001;
ll H[MAXN];
int N;

ll divide_and_conq(int l, int r) {
    if (l == r) return H[l] * H[l];
    
    int m = (l + r) / 2;
    
    ll left_ans = divide_and_conq(l, m);
    ll right_ans = divide_and_conq(m + 1, r);
    
    int lo = m;
    int hi = m + 1;
    
    ll mn = min(H[lo], H[hi]);
    ll sum = H[lo] + H[hi];
    ll cross_ans = sum * mn;
    
    while (lo > l || hi < r) {
        if (hi < r && (lo == l || H[lo - 1] < H[hi + 1])) {
            hi++;
            mn = min(mn, H[hi]); 
            sum += H[hi];
        } 
        else {
            lo--;
            mn = min(mn, H[lo]);
            sum += H[lo];
        }
        
        cross_ans = max(cross_ans, sum * mn);
    }
    
    return max({left_ans, right_ans, cross_ans});
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> H[i];
    cout << divide_and_conq(0, N - 1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();    

    return 0;
}