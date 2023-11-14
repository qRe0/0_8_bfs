#include <iostream>
#include <vector>
#include <queue>
#include <cstdint>

#define int long long

using namespace std;

void bfs(vector<vector<int>>& graphMatrix, vector<bool>& used) {
    queue<int> q;
    q.push(0);
    used[0] = true;

    while (!q.empty()) {
        int curNode = q.front();
        q.pop();

        cout << curNode + 1 << " ";

        for (int neighborNode = 0; neighborNode < graphMatrix.size(); ++neighborNode) {
            if (graphMatrix[curNode][neighborNode] == 1 && !used[neighborNode]) {
                q.push(neighborNode);
                used[neighborNode] = true;
            }
        }
    }
}

int32_t main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> graphMatrix(n, vector<int>(n, 0));
    vector<bool> used(n, false);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> graphMatrix[i][j];

    bfs(graphMatrix, used);

    return 0;
}
