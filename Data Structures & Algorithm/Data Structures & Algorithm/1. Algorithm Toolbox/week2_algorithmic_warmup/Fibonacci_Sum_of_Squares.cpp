#include <iostream>
using namespace std;

long PisanoPeriod()
{
    long x = 0;
    long y = 1;
    long res = 0;

    for (long i = 0; i < 100; i++)
    {
        long tmp = 0;
        tmp = y;
        y = (x + y)%10;
        x = tmp;
        if (x == 0 and y == 1)
            res = i + 1;
    }
    return res;
}
int Huge_Fibonacci_Last_Digit(long long n)
{
    n = n % PisanoPeriod();
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
        y = (x%10 + y%10);
        x = tmp;
    }
    return y%10;
}

int Fibonacci_Sum_of_Squares(long long n)
{
    return (Huge_Fibonacci_Last_Digit(n)*Huge_Fibonacci_Last_Digit(n+1))%10;
}

int main()
{
    long long n = 1;
    cin>>n;
    if (n == 0) cout<<'0';
    else
        cout<<Fibonacci_Sum_of_Squares(n);
    return 0;
}


