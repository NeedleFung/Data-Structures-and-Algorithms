#include <bits/stdc++.h>
using namespace std;
/*
long long BinarySearch(vector<int> &a, long long x)
{
    long long left = 0, right = (long long)a.size()-1;
    long long mid = 0;
    while (left <= right)
    {
        mid = (right - left)/2 + left;
        if (x < a[mid])
        {
            right = mid - 1;
        }
        else if (x > a[mid])
        {
            left = mid + 1;
        }
        else return mid;
    }
    return -1;
}
*/
long long BinarySearch(vector<long long> &a, long long left, long long right, long long q)
{
    if (left > right) return -1;
    else
    {
        long long mid = (right - left) / 2 + left;
        if (q == a[mid])
        {
            if (q == a[mid - 1]) return BinarySearch(a, left, mid - 1, q);
            else return mid;
        }
        else if (q < a[mid]) return BinarySearch(a, left, mid - 1, q);
        else return BinarySearch(a, mid + 1, right, q);
    }
}

long long LinearSearch(vector<long long> &a, long long q)
{
    long long i = 0;
    while (i < a.size() and a[i] != q)
        i++;
    if (i == a.size()) return -1;
    else return i;
}
int main()
{
    /*
    int p = 0;
    while(p == 0)
    {
        long long n = rand() % 20 + 1;
        cout<<n<<endl;
        vector<int> a(n);
        a[0] = rand() % 100;
        for (long long i = 1; i < n; i++)
        {
            a[i] = rand() %100 + a[i-1];
            a.push_back(a[i]);
        }
        long long m = rand() % 20 + 1;
        cout<<m<<endl;
        vector<int> b(m);
        b[0] = rand() % 100;
        for (long long i = 1; i < m; i++)
        {
            b[i] = rand() %100;
            b.push_back(a[i]);
        }
        for (long long i = 0; i < n; i++)
            cout<<a[i]<<' ';
        cout<<endl;
        for (long long i = 0; i < m; i++)
            cout<<b[i]<<' ';
        cout<<endl;
        if (n <= m)
        {
            for (long long i = 0; i < m; i++)
            {
                int res1 = BinarySearch(a, 0, n-1, b[i]);
                int res2 = LinearSearch(a, b[i]);
                if (res1 != res2)
                {
                    cout<<"Wrong answer: "<<res1<<" != "<<res2<<endl;
                    p++;
                    break;
                }
                else cout<<"OK\n";
            }
        }
        else
        {
            for (long long i = 0; i < m; i++)
            {
                int res1 = BinarySearch(a, 0, n-1, b[i]);
                int res2 = LinearSearch(a, b[i]);
                if (res1 != res2)
                {
                    cout<<"Wrong answer: "<<res1<<" != "<<res2<<endl;
                    p++;
                    break;
                }
                else cout<<"OK\n";
            }
        }
    }
    */
    long long n;
    cin>>n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
        cin>>a[i];
    long long m;
    cin>>m;
    vector<long long> b(m);
    for (long long i = 0; i < m; i++)
        cin>>b[i];
    if (n <= m)
    {
        for (long long i = 0; i < m; i++)
            cout<<BinarySearch(a, 0, n-1, b[i])<<' ';
    }
    else
    {
        for (long long i = 0; i < m; i++)
            cout<<BinarySearch(a, 0, n-1, b[i])<<' ';
    }

    return 0;
}

