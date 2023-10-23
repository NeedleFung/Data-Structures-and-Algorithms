#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

long long distance(vector<vector<int>> &adj, vector<vector<pair<int, int>>> &cost, int s, int t)
{
    int n = adj.size();
    vector<long long> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty())
    {
        auto [dist_, curr] = pq.top();
        pq.pop();
        if (curr == t)
            return dist[t];
        if (dist_ != dist[curr])
            continue;
        for (auto& p : cost[curr])
        {
            if (dist[curr] + p.first < dist[p.second])
            {
                pq.push({dist[curr] + p.first, p.second});
                dist[p.second] = dist[curr] + p.first;
            }
        }
    }
    return -1;
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>());
    vector<vector<pair<int, int>>> cost(n, vector<pair<int, int>>());
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        std::cin >> x >> y >> w;
        adj[x - 1].push_back(y - 1);
        cost[x - 1].push_back({w, y - 1});
    }
    int s, t;
    std::cin >> s >> t;
    s--, t--;
    std::cout << distance(adj, cost, s, t);
}
