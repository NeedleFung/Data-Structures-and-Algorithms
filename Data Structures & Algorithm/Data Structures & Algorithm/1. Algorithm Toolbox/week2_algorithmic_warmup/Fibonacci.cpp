#include <iostream>
using namespace std;

long long Fibonacci(int n)
{
    long long x = 0;
    long long y = 1;
    long long tmp = 0;
    for (long i = 2; i <= n; i++)
    {
        tmp = y;
        y = x + y;
        x = tmp;
    }
    return y;
}

int main()
{
    int n;
    cin>>n;
    if (n == 0) cout<<'0';
    else
        cout<<Fibonacci(n);
    return 0;
}
