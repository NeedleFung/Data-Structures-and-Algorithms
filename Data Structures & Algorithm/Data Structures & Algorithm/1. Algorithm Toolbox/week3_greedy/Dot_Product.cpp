#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

void QuickSort(vector<int> &a, int left, int right)
{
    if (left < right)
    {
        int i = left;
        int j = right;
        int t = a[(left + right)/2];
        while (i <= j)
        {
            while (a[i] > t) i++;
            while (a[j] < t) j--;
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

long long maxDot(vector<long long> &a, vector<long long> &b, int n)
{
    long long sum = 0;
    long long a_max, b_max;
    while (n > 0)
    {
        a_max = *max_element(a.begin(), a.end());
        b_max = *max_element(b.begin(), b.end());
        sum += a_max*b_max;
        vector<long long>::iterator pos;
        pos = find(a.begin(), a.end(), a_max);
        if (pos != a.end())
            a.erase(pos);
        pos = find(b.begin(), b.end(), b_max);
        if (pos != b.end())
            b.erase(pos);
        n--;
    }
    return sum;
}

long long MaximumDotProduct(vector<int> &a, vector<int> &b, int n)
{
    QuickSort(a, 0, n-1);
    QuickSort(b, 0, n-1);
    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum +=a[i]*b[i];
    return sum;
}

int main()
{
    int n;
    cin>>n;
    vector<long long> clicks(n), price(n);
    for (int i = 0; i < n; i++)
        cin>>clicks[i];
    for (int i = 0; i < n; i++)
        cin>>price[i];
    cout<<maxDot(clicks, price, n);
    return 0;
}


