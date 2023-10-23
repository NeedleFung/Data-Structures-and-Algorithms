#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

using std::vector;
using std::pair;
int Clock = 1;

void DFShelper(int curr, vector<vector<int>>& reverse_adj, vector<bool>& visited, vector<pair<int, int>>& order)
{
    visited[curr] = true;
    order[curr].first = Clock++;
    for (auto& neighbor : reverse_adj[curr])
    {
        if (!visited[neighbor])
        {
            DFShelper(neighbor, reverse_adj, visited, order);
        }
    }
    order[curr].second = Clock++;
}

vector<pair<int, int>> DFS(vector<vector<int>>& reverse_adj)
{
    int n = reverse_adj.size();
    vector<bool> visited(n, false);
    vector<pair<int, int>> order(n, std::make_pair(0, 0));

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
            DFShelper(i, reverse_adj, visited, order);
    }
    return order;
}

void DFShelper(int curr, vector<vector<int>>& adj, vector<bool>& visited)
{
    visited[curr] = true;
    for (auto& neighbor : adj[curr])
    {
        if (!visited[neighbor])
        {
            DFShelper(neighbor, adj, visited);
        }
    }
}

int number_of_strongly_connected_components(vector<vector<int>>& adj, vector<vector<int>>& reverse_adj)
{
    int result = 0;
    int n = adj.size();
    vector<bool> visited(n, false);
    vector<pair<int, int>> order = DFS(reverse_adj);

    for (int i = 0; i < n; ++i)
    {
        order[i].first = i;
    }

    sort(order.begin(), order.end(), [](const pair<int, int>& x1, const pair<int, int>& x2)
         {
             return x1.second > x2.second;
         });

    for (auto& node : order)
    {
        if (!visited[node.first])
        {
            DFShelper(node.first, adj, visited);
            result++;
        }
    }
    return result;
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>());
    vector<vector<int>> reverse_adj(n, vector<int>());
    for (size_t i = 0; i < m; i++)
    {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        reverse_adj[y - 1].push_back(x - 1);
    }
    std::cout << number_of_strongly_connected_components(adj, reverse_adj);
    return 0;
}
