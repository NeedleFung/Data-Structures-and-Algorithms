#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

bool isBipartite(vector<vector<int>>& adj, vector<int>& color, int src)
{
    int n = adj.size();
    queue<int> q;
    q.push(src);
    color[src] = 0;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (auto& neighbor : adj[curr])
        {
            if (color[neighbor] == color[curr])
                return 0;
            if (color[neighbor] == -1)
            {
                q.push(neighbor);
                color[neighbor] = 1 - color[curr];
            }
        }
    }
    return 1;
}

int bipartite(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (isBipartite(adj, color, i) == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    std::cout << bipartite(adj);
}
