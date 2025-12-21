// Problem: BOJ 25682

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<vector<int>> board;

bool should_change_color(int start_color, int cur_color, int r, int c) {
    if ((r + c) % 2 == 0) return start_color != cur_color;
    else return start_color == cur_color;
}

void solve() {
    int r, c, k; cin >> r >> c >> k;
    board = vector<vector<int>>(r+1, vector<int>(c+1, 0));
    vector<vector<int>> w(r+1, vector<int>(c+1, 0));
    vector<vector<int>> b(r+1, vector<int>(c+1, 0));


    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j){
            char c; cin >> c;
            int color = (c == 'W') ? 1 : -1;
            // 시작을 흰색으로 했을 떄 (i, j)가 바뀌어야하는지 알려주는 변수
            bool is_change_under_white = should_change_color(1, color, i, j);
            bool is_change_under_black = should_change_color(-1, color, i, j);
            w[i+1][j+1] = w[i+1][j] + w[i][j+1] - w[i][j];
            b[i+1][j+1] = b[i+1][j] + b[i][j+1] - b[i][j];
            // 색을 바꿔야하면 그 자리에 +1
            if (is_change_under_white) w[i+1][j+1] ++;
            if (is_change_under_black) b[i+1][j+1] ++;
        }
    }

    int change_color = (1<<30);
    for (int i = 0; i <= r - k; ++i) {
        for (int j = 0; j <= c - k; ++j) {
            int cur_change_color = min( w[i+k][j+k] - w[i][j+k] - w[i+k][j] + w[i][j],
                                        b[i+k][j+k] - b[i][j+k] - b[i+k][j] + b[i][j]);
            change_color = min(change_color, cur_change_color);
        }
    }
    cout << change_color << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}