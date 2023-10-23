#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

class DisjointTree
{
public:
    DisjointTree(int n)
    {
        parent.resize(n + 1);
        _rank.resize(n + 1, 0);
    }

    void makeSet(int i)
    {
        parent[i] = i;
    }

    /*
    int Find(int i)
    {
        while (i != parent[i])
            i = parent[i];
        return i;
    }
    */

    //Path Compression
    int Find(int i)
    {
        if (i != parent[i])
            parent[i] = Find(parent[i]);
        return parent[i];
    }

    void Union(int i, int j)
    {
        int i_id = Find(i);
        int j_id = Find(j);
        if (i_id == j_id)
            return;
        if (_rank[i_id] > _rank[j_id])
            parent[j_id] = i_id;
        else
        {
            parent[i_id] = j_id;
            if (_rank[i_id] == _rank[j_id])
                _rank[j_id] = _rank[j_id] + 1;
        }
    }
public:
    std::vector<int> parent;
    std::vector<int> _rank;
};

int main()
{
    DisjointTree ds(60);
    for (int i = 1; i <= 60; i++)
        ds.makeSet(i);
    for (int i = 1; i <= 30; i++)
        ds.Union(i, 2*i);
    for (int i = 1; i <= 20; i++)
        ds.Union(i, 3*i);
    for (int i = 1; i <= 12; i++)
        ds.Union(i, 5*i);
    std::cout<<*max_element(ds._rank.begin(), ds._rank.end())<<'\n';
    for (int i = 1; i <= 60; i++)
        std::cout<<ds.Find(i)<<' ';
    std::cout<<*max_element(ds._rank.begin(), ds._rank.end())<<'\n';
    return 0;
}

