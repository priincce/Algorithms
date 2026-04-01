#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int v, cap, flow;
};

struct Dinic {
    int n, s, t;
    vector<Edge> edges;
    vector<vector<int>> adj;
    vector<int> level, ptr;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int u, int v, int cap) {
        edges.push_back({v, cap, 0});
        edges.push_back({u, 0, 0});
        adj[u].push_back(edges.size() - 2);
        adj[v].push_back(edges.size() - 1);
    }

    bool bfs() {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        q.push(s);
        level[s] = 0;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int id : adj[u]) {
                Edge &e = edges[id];
                if (e.cap - e.flow > 0 && level[e.v] == -1) {
                    level[e.v] = level[u] + 1;
                    q.push(e.v);
                }
            }
        }
        return level[t] != -1;
    }

    int dfs(int u, int pushed) {
        if (pushed == 0) return 0;
        if (u == t) return pushed;

        for (int &cid = ptr[u]; cid < (int)adj[u].size(); cid++) {
            int id = adj[u][cid];
            Edge &e = edges[id];

            if (level[e.v] != level[u] + 1 || e.cap - e.flow <= 0)
                continue;

            int tr = dfs(e.v, min(pushed, e.cap - e.flow));
            if (tr == 0) continue;

            e.flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    int flow() {
        int f = 0;
        while (bfs()) {
            fill(ptr.begin(), ptr.end(), 0);
            while (int pushed = dfs(s, INT_MAX))
                f += pushed;
        }
        return f;
    }
};

// factorization
map<int,int> factor(int x) {
    map<int,int> res;
    for (int i = 2; i * i <= x; i++) {
        while (x % i == 0) {
            res[i]++;
            x /= i;
        }
    }
    if (x > 1) res[x]++;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<pair<int,int>> edges(m);
    for (auto &e : edges) {
        cin >> e.first >> e.second;
        e.first--, e.second--;
    }

    // factor all numbers
    vector<map<int,int>> fact(n);
    for (int i = 0; i < n; i++)
        fact[i] = factor(a[i]);

    int answer = 0;

    // iterate over all primes
    set<int> primes;
    for (int i = 0; i < n; i++)
        for (auto &p : fact[i])
            primes.insert(p.first);

    for (int p : primes) {
        int S = n, T = n + 1;
        Dinic dinic(n + 2, S, T);

        // source → odd nodes
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) { // 1-based odd
                int cnt = fact[i][p];
                if (cnt > 0)
                    dinic.add_edge(S, i, cnt);
            }
        }

        // even nodes → sink
        for (int i = 0; i < n; i++) {
            if (i % 2 == 1) {
                int cnt = fact[i][p];
                if (cnt > 0)
                    dinic.add_edge(i, T, cnt);
            }
        }

        // edges between good pairs
        for (auto [u, v] : edges) {
            if (u % 2 == 1) swap(u, v); // ensure u is odd-indexed side

            if (u % 2 == 0 && v % 2 == 1) {
                dinic.add_edge(u, v, INT_MAX);
            }
        }

        answer += dinic.flow();
    }

    cout << answer << "\n";
}