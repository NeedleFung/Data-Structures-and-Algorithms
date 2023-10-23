#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using std::vector;
using std::pair;
using std::queue;

int DFShelper(int v, vector<vector<int>> &adj, int visited[])
{
    visited[v] = 1;
    for (auto& neighbor : adj[v])
    {
        if (visited[neighbor] == 1) return 1;
        if (visited[neighbor] == 0 && DFShelper(neighbor, adj, visited) == 1)
            return 1;
    }
    visited[v] = 2;
    return 0;
}

int acyclic(vector<vector<int>> &adj)
{
    int visited[adj.size()];
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < adj.size(); ++i)
    {
        if (visited[i] == 0 && DFShelper(i, adj, visited) == 1)
            return 1;
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
    }
    std::cout << acyclic(adj);
}
