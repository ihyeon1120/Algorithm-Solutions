#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct Node{
    Node *left, *right;
    ll v;
    Node() { left = right = nullptr; v = 0; }
};

struct PersistentSegmentTree
{
    vector<Node*> roots;
    vector<ll> arr;
    int sz;

    ll merge(ll a, ll b) { return a + b; }
    
    PersistentSegmentTree(const vector<ll>& a) {
        arr = a;
        sz = sz(arr);
        Node* root_v0 = new Node();
        init(root_v0, 0, sz-1);
        roots.push_back(root_v0);
    }

    void init(Node* node, int s, int e){
        if (s == e) node->v = arr[s];
        else{
            int m = (s + e) / 2;
            node->left = new Node();
            node->right = new Node();

            init(node->left, s, m);
            init(node->right, m+1, e);

            node->v = merge(node->left->v, node->right->v);
        }
    }

    // 이전 버전을 기반으로 index의 값을 val로 바꾼 새로운 버전을 생성
    void update(int pre_version, int index, ll val){
        Node* new_root = new Node();
        update_recusive(roots[pre_version], new_root, 0, sz-1, index, val);
        roots.push_back(new_root);
    }

    void update_recusive(Node* prev, Node* curr, int s, int e, int index, ll val){
        if (s == e){
            curr->v = val;
            return;
        }

        int m = (s + e) / 2;
        if (index <= m){
            curr->left = new Node();
            curr->right = prev->right;
            update_recusive(prev->left, curr->left, s, m, index, val);
        } else {
            curr->right = new Node();
            curr->left = prev->left;
            update_recusive(prev->right, curr->right, m + 1, e, index, val);
        }

        curr->v = merge(curr->left->v, curr->right->v);
        
    }

    ll query(int version, int left, int right){
        return recursive_query(roots[version], 0, sz-1, left, right);
    }

    ll recursive_query(Node* node, int s, int e, int left, int right) {
        if (right < s || e < left || node == nullptr) return 0;
        if (left <= s && e <= right) return node->v;
        int m = (s + e) / 2;
        ll lsum = recursive_query(node->left, s, m, left, right);
        ll rsum = recursive_query(node->right, m+1, e, left, right);
        return merge(lsum, rsum);
    }
};

void solve(){
    int N; cin >> N;
    vector<ll> a(N); for(int i = 0; i<N; i++) cin >> a[i];
    PersistentSegmentTree pst{a};
    int M; cin >> M;
    int version = 0;
    while (M--){
        int a; cin >> a;
        if (a == 1){
            int b, c; cin >> b >> c;
            pst.update(version++, b-1, c);
        }
        else if (a == 2)
        {
            int k, i, j; cin >> k >> i >> j;
            cout << pst.query(k, i-1, j-1) << endl;
        }
        
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}