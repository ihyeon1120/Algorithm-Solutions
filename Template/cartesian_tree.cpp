#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 200001;
int L[MAXN], R[MAXN];
int P[MAXN];
int n;

void build_tree() {
    fill(L, L + n + 1, 0);
    fill(R, R + n + 1, 0);
    stack<int> st;
    for (int i = 1; i <= n; ++i) {
        int last_popped = 0;
        while(!st.empty() && P[st.top()] < P[i]) {
            last_popped = st.top(); st.pop();
        }
        L[i] = last_popped;
        if (!st.empty()) {
            R[st.top()] = i;
        }
        st.push(i);
    }
}

int main() {
    build_tree();
    return 0;
}