#include <bits/stdc++.h>
using namespace std;

void QuickSort(vector<long long> &a, long left, long right)
{
    if (left <= right)
    {
        long i = left;
        long j = right;
        long t = a[left + (right - left)/2];
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

long MajorityElement(vector<long long> &a)
{
    QuickSort(a, 0, a.size() - 1);
    if (a.size() == 1) return 1;
    else
    {
        long count = 1;
        for(long i = 1; i < a.size(); i++)
        {
            if (a[i] == a[i - 1]) count++;
            else count = 1;
            if (count > int(a.size()/2))
            {
                return 1;
                break;
            }
        }
        return 0;
    }
}

int main()
{
    long n = 0;
    cin>>n;
    vector<long long> a(n);
    for (long i = 0; i < n; i++)
        cin>>a[i];
    cout<<MajorityElement(a);
    return 0;
}
