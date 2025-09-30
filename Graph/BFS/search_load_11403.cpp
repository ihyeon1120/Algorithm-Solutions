// Problem: BOJ 11403

#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

// INF 상수를 정의하여 가독성과 안정성을 높입니다.
const int INF = 1e9; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int k;
            cin >> k;
            if (k == 1) {
                graph[i][j] = 1;
            } else {
                graph[i][j] = INF; // 0이면 길이 없는 것이므로 INF로 저장
            }
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // i->k 와 k->j 경로가 모두 존재할 때만 업데이트
                if (graph[i][k] != INF && graph[k][j] != INF) {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << (graph[i][j] == INF ? 0 : 1) << " ";
        }
        cout << endl;
    }

    return 0;
}