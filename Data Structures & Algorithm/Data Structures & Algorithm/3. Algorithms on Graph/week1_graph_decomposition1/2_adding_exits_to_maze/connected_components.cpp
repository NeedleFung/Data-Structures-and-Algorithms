#include <iostream>
#include <vector>
#include <cstring>

using std::vector;
using std::pair;

void DFShelper(int v, vector<vector<int>> &adj, bool visited[])
{
    visited[v] = true;
    for (auto& neighbor : adj[v])
    {
        if (!visited[neighbor])
            DFShelper(neighbor, adj, visited);
    }
}

int number_of_components(vector<vector<int>> &adj)
{
    int n = adj.size();
    bool visited[n];
    memset(visited, false, sizeof(visited));
    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            DFShelper(i, adj, visited);
            res++;
        }
    }
    return res;
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
    std::cout << number_of_components(adj);
    return 0;
}
