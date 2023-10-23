#include <iostream>
#include <vector>
#include <climits>
#include <cstring>

using std::vector;

//Bellman - Ford Algorithm
bool BellmanFord(int curr, vector<vector<int>> &adj, vector<vector<int>> &cost, vector<int> &dist) {
    int n = adj.size();
    dist[curr] = 0;
    for (int i = 1; i <= n - 1; ++i) {
        for (int curr = 0; curr < n; ++curr) {
            int m = adj[curr].size();
            for (int next = 0; next < m; ++next) {
                int neighbor = adj[curr][next];
                int weight = cost[curr][next];
                if (dist[curr] != INT_MAX && dist[neighbor] > dist[curr] + weight) {
                    dist[neighbor] = dist[curr] + weight;
                }
            }
        }
    }

    for (int curr = 0; curr < n; ++curr) {
        int m = adj[curr].size();
        for (int next = 0; next < m; ++next) {
            int neighbor = adj[curr][next];
            int weight = cost[curr][next];
            if (dist[curr] != INT_MAX && dist[neighbor] > dist[curr] + weight) {
                return true;
            }
        }
    }
    return false;
}

int negative_cycle(vector<vector<int>> &adj, vector<vector<int>> &cost) {
    int n = adj.size();
    bool visited[n];
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < n; ++i) {
        vector<int> dist(n, INT_MAX);
        if (visited[i] == false) {
            if (BellmanFord(i, adj, cost, dist))
                return 1;

            for (int i = 0; i < n; ++i)
                if (dist[i] != INT_MAX)
                    visited[i] = true;
        }
    }

    return 0;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>());
    vector<vector<int>> cost(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y, w;
        std::cin >> x >> y >> w;
        adj[x - 1].push_back(y - 1);
        cost[x - 1].push_back(w);
    }
    std::cout << negative_cycle(adj, cost);
}
