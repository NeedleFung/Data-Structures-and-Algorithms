#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int n;
struct Item
{
    double v, w;
};

struct List
{
    Item I[MAX];
    int count;
};
List L;

void Initialise(List &L)
{
    L.count = -1;
}

void AddList(List &L)
{
    Initialise(L);
    Item X;
    int i = 1;
    do
    {
        cin>>X.v>>X.w;
        L.count++;
        L.I[L.count] = X;
        i++;
    } while(i <= n);
}

void QuickSort(List &L, int left, int right)
{
    if (left < right)
    {
        int i = left;
        int j = right;
        double val = L.I[(left + right)/2].v / L.I[(left + right)/2].w;
        while (i <= j)
        {
            while (double(L.I[i].v / L.I[i].w) > val) i++;
            while (double(L.I[j].v / L.I[j].w) < val) j--;
            if (i <= j)
            {
                swap(L.I[i], L.I[j]);
                i++;
                j--;
            }
        }
        QuickSort(L, left, j);
        QuickSort(L, i, right);
    }
}
double KnapsackFast(List &L, double Weight)
{
    double totalValue = 0;
    QuickSort(L, 0, n-1);
    for (int i = 0; i <= L.count; i++)
    {
        if (Weight == 0) return totalValue;
        double a = min(L.I[i].w, Weight);
        double val = double(L.I[i].v / L.I[i].w);
        totalValue += a*val;
        Weight -= a;
    }
    return totalValue;
}
int main()
{
    cin>>n;
    double W;
    cin>>W;
    List L;
    AddList(L);
    cout<<fixed<<KnapsackFast(L,W);
    return 0;
}


