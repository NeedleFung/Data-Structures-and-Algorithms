#include <iostream>
#include <vector>
#include <algorithm>

class NaiveDisjointSet
{
public:
    NaiveDisjointSet(int n)
    {
        smallest.resize(n + 1, 0);
    }

    void makeSet(int i)
    {
        smallest[i] = i;
    }

    int Find(int i)
    {
        return smallest[i];
    }

    void Union(int i, int j)
    {
        int i_id = Find(i);
        int j_id = Find(j);
        if (i_id == j_id)
            return;
        int m = std::min(i_id, j_id);
        for (int k = 1; k < smallest.size(); k++)
        {
            if (smallest[k] == i_id || smallest[k] == j_id)
                smallest[k] = m;
        }
    }
private:
    std::vector<int> smallest;
};

int main()
{
    NaiveDisjointSet ds(12);
    for (int i = 1; i <= 12; i++)
        ds.makeSet(i);
    ds.Union(2, 10);
    ds.Union(7, 5);
    ds.Union(6, 1);
    ds.Union(3, 4);
    ds.Union(5, 11);
    ds.Union(7, 8);
    ds.Union(7, 3);
    ds.Union(12, 2);
    ds.Union(9, 6);
    std::cout<<ds.Find(6)<<'\n';
    std::cout<<ds.Find(3)<<'\n';
    std::cout<<ds.Find(11)<<'\n';
    std::cout<<ds.Find(9)<<'\n';
    return 0;
}

