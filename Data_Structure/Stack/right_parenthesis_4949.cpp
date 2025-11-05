// Problem: BOJ 4949

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool right_parenthesis(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[') {
            st.push(c);
        }
        else if (c == ')' || c == ']') {
            if (st.empty()) return false;
            char t = st.top();
            if ((c == ')' && t == '(') || (c == ']' && t == '[')) st.pop();
            else return false;
        }
        else continue;
    }
    if (!st.empty()) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(1) {
        string s; getline(cin, s);
        if (s == ".") break;
        string ans = (right_parenthesis(s) ? "yes" : "no");
        cout << ans << endl;
    }

    return 0;
}