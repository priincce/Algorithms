#include <bits/stdc++.h>
using namespace std;

vector<int> heights, first_occur, euler;
vector<bool> vis;
vector<vector<int>> st; // sparse table storing indexes
vector<int> logVal;     // precomputed logs

void dfs(vector<vector<int>>& adj, int node, int height = 0) {
    vis[node] = true;
    heights[node] = height;
    first_occur[node] = euler.size();
    euler.push_back(node);

    for (auto nbr : adj[node]) {
        if (!vis[nbr]) {
            dfs(adj, nbr, height + 1);
            euler.push_back(node); // backtrack
        }
    }
}

// Build Sparse Table for RMQ on heights[] over euler tour
void buildSparseTable() {
    int m = euler.size();
    int K = log2(m) + 1;

    st.assign(m, vector<int>(K));
    logVal.assign(m + 1, 0);

    // Base case: intervals of length 1
    for (int i = 0; i < m; i++) {
        st[i][0] = i; // store index in euler array
    }

    // Precompute logs
    for (int i = 2; i <= m; i++)
        logVal[i] = logVal[i / 2] + 1;

    // Build Sparse Table
    for (int j = 1; (1 << j) <= m; j++) {
        for (int i = 0; i + (1 << j) <= m; i++) {
            int idx1 = st[i][j - 1];
            int idx2 = st[i + (1 << (j - 1))][j - 1];
            st[i][j] = (heights[euler[idx1]] < heights[euler[idx2]]) ? idx1 : idx2;
        }
    }
}

int rmqIndex(int L, int R) {
    int j = logVal[R - L + 1];
    int idx1 = st[L][j];
    int idx2 = st[R - (1 << j) + 1][j];
    return (heights[euler[idx1]] < heights[euler[idx2]]) ? idx1 : idx2;
}

int lca(int u, int v) {
    int left = first_occur[u], right = first_occur[v];
    if (left > right) swap(left, right);
    int idx = rmqIndex(left, right);
    return euler[idx];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    heights.resize(n + 1);
    first_occur.resize(n + 1, -1);
    vis.assign(n + 1, false);

    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u;
        cin >> u;
        adj[u].push_back(i + 1);
        adj[i + 1].push_back(u);
    }

    dfs(adj, 1);
    buildSparseTable();

    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << "\n";
    }
    return 0;
}
