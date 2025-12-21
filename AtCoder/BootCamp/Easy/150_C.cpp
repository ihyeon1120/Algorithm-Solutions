#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> permu;

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void permutation(vector<int> data, int depth, int n, int r)
{
    if (depth == r)
    {
        string t = "";
        for(int i = 0; i < r; i++)
            t += to_string(data[i]);
        permu.push_back(stoi(t));
        return;
    }
    
    for(int i = depth; i < n; i++)
    {
        swap(data[depth], data[i]);
        permutation(data, depth + 1, n, r);
        swap(data[depth], data[i]);
    }
}

void solve() {
    int n; cin >> n;
    vector<int> a;
    for (int i = 1; i < n + 1; ++i) a.push_back(i);
    permutation(a, 0, n, n);
    sort(all(permu));
    string p;
    string q;
    int i1, i2;
    for (int i  = 0; i < n; ++i) {char c; cin >> c; p.push_back(c);}
    for (int i  = 0; i < n; ++i) {char c; cin >> c; q.push_back(c);}
    int ip = stoi(p);
    int iq = stoi(q);
    for (int i  = 0; i < sz(permu); ++i) {
        if (ip == permu[i]) i1 = i;
        if (iq == permu[i]) i2 = i;
    }
    cout << abs(i1 - i2) << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}