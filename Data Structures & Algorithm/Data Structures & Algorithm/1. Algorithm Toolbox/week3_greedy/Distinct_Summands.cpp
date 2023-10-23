#include <iostream>
#include <math.h>
#include <vector>
#include <numeric>
using namespace std;

/*void MaximumPrize(long n)
{
    long S = 0;
    long M = n;
    int j = 0;
    int *a = new int [j];
    a[j] = 0;

    for (int i = 1; i <= n; i++)
    {
        if (M < i)
        {
            S += M;
            a[j-1] = (i-1) + M;
            break;
        }
        else
        {
            S += i;+
            M -= i;
            a[j] = i;
            j++;
        }
    }
    cout<<j<<endl;
    for (int i = 0; i < j; i++)
        cout<<a[i]<<' ';
}*/

int main()
{
    long long n;
    cin>>n;
    long long k = (sqrt(8*n + 1) - 1)/2;
    vector<long> numbers(k);

    for (int i = 0; i < numbers.size(); i++)
        numbers[i] = i+1;
    long long sum = accumulate(numbers.begin(), numbers.end(), 0);
    if (sum < n) numbers[k-1] = k + n - sum;
    cout<<k<<endl;
    for (int i = 0; i < numbers.size(); i++)
        cout<<numbers[i]<<' ';

    return 0;
}
