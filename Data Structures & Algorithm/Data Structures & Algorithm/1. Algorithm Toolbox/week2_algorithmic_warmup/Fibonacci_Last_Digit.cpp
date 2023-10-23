#include <iostream>
using namespace std;

int Fibonacci_Last_Digit(int n)
{
    int x = 0;
    int y = 1;
    int tmp = 0;
    for(int i = 2; i <= n; i++)
    {
        tmp = y;
        y = (x%10 + y%10);
        x = tmp;
    }
    return y%10;
}

int main()
{
    int n;
    cin>>n;
    if (n == 0) cout<<'0';
    else
        cout<<Fibonacci_Last_Digit(n);
    return 0;
}
