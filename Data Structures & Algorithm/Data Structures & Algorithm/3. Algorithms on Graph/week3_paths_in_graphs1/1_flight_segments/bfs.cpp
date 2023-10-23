#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int distance(vector<vector<int>> &adj, int s, int t)
{
    int n = adj.size();
    vector<int> distance(n, -1);
    queue<int> q;
    q.push(s);
    distance[s] = 0;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        if (curr == t)
            return distance[curr];
        for (auto& neighbor : adj[curr])
        {
            if (distance[neighbor] == -1)
            {
                distance[neighbor] = distance[curr] + 1;
                q.push(neighbor);
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
    for (int i = 0; i < m; i++)
    {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    int s, t;
    std::cin >> s >> t;
    s--, t--;
    std::cout << distance(adj, s, t);
}
