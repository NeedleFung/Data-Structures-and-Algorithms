#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    long long n;
    std::cin>>n;
    std::vector<long long> a(n+1, 0);
    for (long long i = 1; i <= n; i++)
    {
        a[i] = a[i-1] + 1;
        if (i % 2 == 0) a[i] = std::min(a[i/2] + 1, a[i]);
        if (i % 3 == 0) a[i] = std::min(a[i/3] + 1, a[i]);
    }
    std::vector<long long> b;
    b.push_back(n);
    long long m = n;
    while (m > 1)
    {
        if (m % 3 == 0 && a[m/3] == a[m] - 1)
            m = m / 3;
        else if (m % 2 == 0 && a[m/2] == a[m] - 1)
            m = m / 2;
        else if (a[m] == a[m-1] + 1)
            m--;
        b.push_back(m);
    }
    std::reverse(b.begin(), b.end());
    std::cout<< a[n] - 1 <<'\n';
    for (long long i = 0; i < b.size(); i++)
        std::cout<<b[i]<<' ';
    return 0;
}
