#include <iostream>
using namespace std;

long PisanoPeriod(long m)
{
    long x = 0;
    long y = 1;
    long res = 0;

    for (long i = 0; i < m*m; i++)
    {
        long tmp = 0;
        tmp = y;
        y = (x + y)%m;
        x = tmp;
        if (x == 0 and y == 1)
            res = i + 1;
    }
    return res;
}
int Huge_Fibonacci(long long n, int m)
{
    n = n % PisanoPeriod(m);
    int x = 0;
    int y = 1;
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    for(long long i = 2; i <= n; i++)
    {
        int tmp = 0;
        tmp = y;
        y = (x%m + y%m);
        x = tmp;
    }
    return y%m;
}

int main()
{
    long long n = 1;
    int m = 2;
    cin>>n>>m;
    cout<<Huge_Fibonacci(n, m);
    return 0;
}

