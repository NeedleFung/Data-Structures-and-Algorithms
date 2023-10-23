#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 0;
    long x = 1048576;
    long y = 2097152;
    while(abs(x - y) != 1)
    {
        cin>>a;
        long z = x;
        if (a == 0) x = x - abs(x - y)/2;
        else x = x + abs(x - y)/2;
        y = z;
        cout<<x<<endl;
    }
    return 0;
}

