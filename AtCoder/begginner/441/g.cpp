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

#ifndef ONLINE_JUDGE
template<typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& p) {
    return os << "{" << p.first << ", " << p.second << "}";
}
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1) os << ", ";
    }
    return os << "]";
}

#define debug(...) cerr << "[DEBUG] " << #__VA_ARGS__ << ": ", DBG(__VA_ARGS__)
template<typename T> void DBG(const T& v) { cerr << v << endl; }
template<typename T, typename... Args> void DBG(const T& v, const Args&... args) { cerr << v << ", "; DBG(args...); }
#else
#define debug(...)
#endif

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_N = 200005;

enum State {
    ALL_UP = 1,
    ALL_DOWN = 2,
    MIXED = 3
};

struct Node {
    ll max_val;
    State state;
    
    ll lazy_add;
    bool lazy_set0;
    bool lazy_flip;
} tree[MAX_N * 4];

int n, q;

State merge_state(State left, State right) {
    if (left == right) return left;
    return MIXED;
}

void build(int node, int start, int end) {
    tree[node].max_val = 0;
    tree[node].state = ALL_UP;
    tree[node].lazy_add = 0;
    tree[node].lazy_set0 = false;
    tree[node].lazy_flip = false;

    if (start == end) return;
    int mid = (start + end) / 2;
    build(node * 2, start, mid);
    build(node * 2 + 1, mid + 1, end);
}

void push(int node, int start, int end) {
    int left = node * 2;
    int right = node * 2 + 1;

    if (tree[node].lazy_set0) {
        tree[left].max_val = 0;
        tree[left].lazy_add = 0;
        tree[left].lazy_set0 = true;
        
        tree[right].max_val = 0;
        tree[right].lazy_add = 0;
        tree[right].lazy_set0 = true;

        tree[node].lazy_set0 = false;
    }

    if (tree[node].lazy_flip) {
        if (tree[left].state == ALL_UP) tree[left].state = ALL_DOWN;
        else if (tree[left].state == ALL_DOWN) tree[left].state = ALL_UP;
        tree[left].lazy_flip = !tree[left].lazy_flip;

        if (tree[right].state == ALL_UP) tree[right].state = ALL_DOWN;
        else if (tree[right].state == ALL_DOWN) tree[right].state = ALL_UP;
        tree[right].lazy_flip = !tree[right].lazy_flip;

        tree[node].lazy_flip = false;
    }

    if (tree[node].lazy_add != 0) {
        tree[left].max_val += tree[node].lazy_add;
        tree[left].lazy_add += tree[node].lazy_add;

        tree[right].max_val += tree[node].lazy_add;
        tree[right].lazy_add += tree[node].lazy_add;

        tree[node].lazy_add = 0;
    }
}

void update_add(int node, int start, int end, int l, int r, int x) {
    if (r < start || end < l) return;

    if (l <= start && end <= r) {
        if (tree[node].state == ALL_DOWN) {
            return;
        }
        if (tree[node].state == ALL_UP) {
            tree[node].max_val += x;
            tree[node].lazy_add += x;
            return; 
        }
    }

    push(node, start, end);
    int mid = (start + end) / 2;
    update_add(node * 2, start, mid, l, r, x);
    update_add(node * 2 + 1, mid + 1, end, l, r, x);
    
    tree[node].max_val = max(tree[node * 2].max_val, tree[node * 2 + 1].max_val);
    tree[node].state = merge_state(tree[node * 2].state, tree[node * 2 + 1].state);
}

void update_type2(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return;

    if (l <= start && end <= r) {
        tree[node].max_val = 0;
        tree[node].lazy_add = 0;
        tree[node].lazy_set0 = true;
        
        if (tree[node].state == ALL_UP) tree[node].state = ALL_DOWN;
        else if (tree[node].state == ALL_DOWN) tree[node].state = ALL_UP;
        tree[node].lazy_flip = !tree[node].lazy_flip;
        return;
    }

    push(node, start, end);
    int mid = (start + end) / 2;
    update_type2(node * 2, start, mid, l, r);
    update_type2(node * 2 + 1, mid + 1, end, l, r);

    tree[node].max_val = max(tree[node * 2].max_val, tree[node * 2 + 1].max_val);
    tree[node].state = merge_state(tree[node * 2].state, tree[node * 2 + 1].state);
}

ll query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return 0;
    if (l <= start && end <= r) return tree[node].max_val;

    push(node, start, end);
    int mid = (start + end) / 2;
    return max(query(node * 2, start, mid, l, r),
               query(node * 2 + 1, mid + 1, end, l, r));
}

void solve() {
    cin >> n >> q;
    build(1, 1, n);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            update_add(1, 1, n, l, r, x);
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;
            update_type2(1, 1, n, l, r);
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}