#include <bits/stdc++.h>
using namespace std;

long long NaiveInversions(vector<long long> &a)
{
    long long count = 0;
    for (int i = 0; i < a.size() - 1; i++)
        for (int j = i + 1; j < a.size(); j++)
            if (a[i] > a[j]) count++;
    return count;
}

int main()
{
    long n = 0;
    cin>>n;
    vector<long long> a(n);
    for (long i = 0; i < n; i++)
        cin>>a[i];
    cout<<NaiveInversions(a);
    return 0;
}
