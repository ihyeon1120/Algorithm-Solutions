#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll INF = 4e18; 

int n, q;

vector<ll> tree1; // X + Y
vector<ll> tree2; // X - Y
vector<ll> tree3; // -X + Y
vector<ll> tree4; // -X - Y

void update(int node, int start, int end, int idx, ll x, ll y) {
    if (idx < start || idx > end) return;
        if (start == end) {
        tree1[node] = x + y;
        tree2[node] = x - y;
        tree3[node] = -x + y;
        tree4[node] = -x - y;
        return;
    }
    
    int mid = (start + end) / 2;
    update(node * 2, start, mid, idx, x, y);
    update(node * 2 + 1, mid + 1, end, idx, x, y);
    
    tree1[node] = max(tree1[node * 2], tree1[node * 2 + 1]);
    tree2[node] = max(tree2[node * 2], tree2[node * 2 + 1]);
    tree3[node] = max(tree3[node * 2], tree3[node * 2 + 1]);
    tree4[node] = max(tree4[node * 2], tree4[node * 2 + 1]);
}

ll query(vector<ll> &t, int node, int start, int end, int left, int right) {
    if (left > end || right < start) return -INF;
    
    if (left <= start && end <= right) return t[node];
    
    int mid = (start + end) / 2;
    return max(query(t, node * 2, start, mid, left, right),
               query(t, node * 2 + 1, mid + 1, end, left, right));
}

void solve() {
    cin >> n >> q;
    
    tree1.resize(4 * n + 1, -INF);
    tree2.resize(4 * n + 1, -INF);
    tree3.resize(4 * n + 1, -INF);
    tree4.resize(4 * n + 1, -INF);
    
    for (int i = 1; i <= n; ++i) {
        ll x, y; cin >> x >> y;
        update(1, 1, n, i, x, y);
    }
    
    while(q--) {
        int type; cin >> type;
        
        if (type == 1) {
            int i; 
            ll x, y; 
            cin >> i >> x >> y;
            update(1, 1, n, i, x, y);
        } 
        else {
            int l, r;
            ll x, y;
            cin >> l >> r >> x >> y;
            ll m1 = query(tree1, 1, 1, n, l, r);
            ll m2 = query(tree2, 1, 1, n, l, r);
            ll m3 = query(tree3, 1, 1, n, l, r);
            ll m4 = query(tree4, 1, 1, n, l, r);
            
            ll ans = -INF;
            ans = max(ans, m1 - (x + y));
            ans = max(ans, m2 - (x - y));
            ans = max(ans, m3 - (-x + y));
            ans = max(ans, m4 - (-x - y));
            
            cout << ans << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}