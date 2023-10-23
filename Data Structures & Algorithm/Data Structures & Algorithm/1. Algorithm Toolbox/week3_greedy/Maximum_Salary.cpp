#include <iostream>
#include <string>
using namespace std;
long Concat(int a, int b)
{
    string output;
    string str1 = to_string(a);
    string str2 = to_string(b);
    output = str1 + str2;
    return (long)stoi(output);
}

void LargestNumber(int *t, int n)
{
    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++)
            if(Concat(t[i], t[j]) < Concat(t[j], t[i]))
                swap(t[i], t[j]);
}

int main()
{
    int n;
    cin>>n;
    int *t = new int [n];
    for (int i = 0; i < n; i++)
        cin >> t[i];
    LargestNumber(t, n);
    for(int i = 0; i<n; i++)
        cout<<t[i];
    return 0;
}
