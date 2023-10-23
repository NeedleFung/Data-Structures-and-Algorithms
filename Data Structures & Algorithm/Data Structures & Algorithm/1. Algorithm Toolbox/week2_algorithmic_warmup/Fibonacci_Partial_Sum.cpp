#include <iostream>
#include <cstdlib>
using namespace std;

int Fib_Sum(int m, int n)
{
    int x = 0;
    int y = 1;
    int sum1 = 1;
    if (m <= 1) sum1 = 0;
    for (int i = 2; i < m; i++)
    {
        int tmp = y;
        y = x + y;
        x = tmp;
        sum1 += y;
    }
    x = 0;
    y = 1;
    int sum2 = 1;
    if (n < 1) sum2 = 0;
    for (int i = 2; i <= n; i++)
    {
        int tmp = y;
        y = x + y;
        x = tmp;
        sum2 += y;
    }
    cout<<endl<<sum1<<' '<<sum2;
    if (m == n and m == 0) return 0;
    if (m == n) return y%10;
    return (sum2 - sum1)%10;
}

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

int Fibonacci_Sum(long long a)
{
    if(Huge_Fibonacci_Last_Digit(a+2) == 0) return 9;
    else return Huge_Fibonacci_Last_Digit(a+2) - 1;
}

int Fibonacci_Partial_Sum(long long m, long long n)
{
    if (m == n) return Huge_Fibonacci_Last_Digit(m);
    else return (Fibonacci_Sum(n)+10 - Fibonacci_Sum(m-1))%10;
}

int main()
{
    /*while (true)
    {
        int m = rand() %10;
        int n = rand() %10 + m;
        cout<<m<<' '<<n;
        int x = Fib_Sum(m, n);
        int y = Fibonacci_Partial_Sum(m,n);
        if (x == y)
            cout<<"\nRight answer: "<<x<<" = "<<y<<endl;
        else
        {
            cout<<"\nWrong answer: "<<x<<" != "<<y;
            break;
        }

    }*/
    long long m = 0;
    long long n = 0;
    cin>>m>>n;
    if (n == 0) cout<<'0';
    else
        cout<<Fibonacci_Partial_Sum(m, n);
    return 0;
}



