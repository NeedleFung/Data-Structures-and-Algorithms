#include <iostream>
using namespace std;

long long GCD(long long a, long long b)
{
    if (b == 0) return a;
    long long p = a%b;
    return GCD(b, p);
}

long long LCM (long long a, long long b)
{
    long long p = GCD(a, b);
    return (a*b)/p;
}

int main()
{
    long long a = 0;
    long long b = 0;
    cin>>a>>b;
    cout<<LCM(a, b);
    return 0;
}

