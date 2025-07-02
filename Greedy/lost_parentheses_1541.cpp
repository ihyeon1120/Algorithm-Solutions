// Problem: BOJ 1541
/*
아이디어: -가 나오면 다음 -가 나오기 전까지 ans에 값을 빼줌
*/
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

    string s; cin >> s;
    int n = sz(s);
    int ans = 0;
    bool flag = false;
    string num = "";
    for (int i = 0; i <= n; i++)
    {
        
        if (s[i] == '+' || s[i] == '-' || i == n){
            if (flag) {
                ans -= stoi(num);
            } else {
                ans += stoi(num);
            }
            num = "";
        }
        
        else {
            num += s[i];
        }
        
        if (s[i] == '-') flag = true;
    }
    
    cout << ans <<  endl;

    return 0;
}