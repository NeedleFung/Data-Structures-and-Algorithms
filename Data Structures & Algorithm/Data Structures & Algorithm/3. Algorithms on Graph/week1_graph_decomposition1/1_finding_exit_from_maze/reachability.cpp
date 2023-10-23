#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::pair;
using std::queue;

int reach(vector<vector<int>> &adj, int x, int y)
{
    int vertices = adj.size();
    vector<bool> visited(vertices, false);
    queue<int> q;
    q.push(x);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        if (curr == y)
            return 1;
        for (auto neighbor : adj[curr])
        {
            if (!visited[neighbor])
            {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    return 0;
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>());
    for (size_t i = 0; i < m; i++)
    {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    int x, y;
    std::cin >> x >> y;
    std::cout << reach(adj, x - 1, y - 1);
    return 0;
}
