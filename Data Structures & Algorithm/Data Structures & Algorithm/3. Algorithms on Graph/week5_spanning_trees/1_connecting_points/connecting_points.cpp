#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using std::vector;
using std::pair;

class UnionFind
{
public:
    vector<int> parent;
    vector<int> rank;
    UnionFind(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int Find(int i)
    {
        if (i == parent[i])
            return i;
        parent[i] = Find(parent[i]);
        return parent[i];
    }

    bool Union(int i, int j)
    {
        int i_id = Find(i);
        int j_id = Find(j);
        if (i_id == j_id)
            return false;
        if (rank[i_id] > rank[j_id])
            parent[j_id] = i_id;
        else
        {
            parent[i_id] = j_id;
            if (rank[i_id] == rank[j_id])
                rank[j_id]++;
        }
        return true;
    }
};

double Distance(vector<int>& p1, vector<int>& p2)
{
    return sqrt(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2));
}

double minimum_distance(vector<vector<int>>& points)
{
    int n = points.size();
    UnionFind uf(n);
    vector<pair<double, pair<int, int>>> edges;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            double distance = Distance(points[i], points[j]);
            edges.push_back({distance, {i, j}});
        }

    sort(edges.begin(), edges.end());
    double minCost = 0.;
    int countEdges = 0;
    for (auto& edge : edges)
    {
        double distance = edge.first;
        int curr = edge.second.first;
        int next = edge.second.second;
        if (uf.Union(curr, next))
        {
            minCost += distance;
            countEdges++;
        }

        if (countEdges == n - 1)
            break;
    }
    return minCost;
}

int main()
{
    size_t n;
    std::cin >> n;
    vector<vector<int>> points(n, vector<int> (n));
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> points[i][0] >> points[i][1];
    }
    std::cout << std::setprecision(10) << minimum_distance(points);
    return 0;
}
