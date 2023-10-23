#include <iostream>
using namespace std;

int MoneyChange(int n)
{
    int num1 = 0;
    int num2 = 0;
    if (n >= 10)
    {
        num1 = n/10;
        n = n%10;
    }
    if (n >= 5)
    {
        num2 = n/5;
        n = n%5;
    }
    int num = num1 + num2 + n;
    return num;
}

int main()
{
    int n;
    cin>>n;
    cout<<MoneyChange(n);
    return 0;
}
