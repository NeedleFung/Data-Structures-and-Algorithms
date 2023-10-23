#include <iostream>
#include <vector>
using namespace std;

void QuickSort(vector<long long> &a, int left, int right)
{
    if (left <= right)
    {
        int i = left;
        int j = right;
        int t = a[(left + right)/2];
        while (i <= j)
        {
            while (a[i] < t) i++;
            while (a[j] > t) j--;
            if (i <= j)
            {
                swap(a[i], a[j]);
                i++;
                j--;
            }
        }
        QuickSort(a, left, j);
        QuickSort(a, i, right);
    }
}

int main()
{
    int n;
    cin>>n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin>>a[i];
    QuickSort(a, 0, n-1);
    for (int i = 0; i < n; i++)
        cout<<a[i]<<' ';
    return 0;
}
