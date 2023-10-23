#include <iostream>
using namespace std;

void QuickSort(int *t, int left, int right)
{
    if(left < right)
    {
        int i = left;
        int j = right;
        int k = t[(left + right)/2];
        while (i <= j)
        {
            while (t[i] < k) i++;
            while (t[j] > k) j--;
            if (i <= j)
            {
                swap(t[i], t[j]);
                i++;
                j--;
            }
        }
        QuickSort(t, left, j);
        QuickSort(t, i, right);
    }
}
int MinTotalWaitingTime(int *t, int n)
{
    QuickSort(t, 0, n-1);
    int waitingTime = 0;
    for (int i = 0; i < n; i++)
        waitingTime += (n-i-1)*t[i];
    return waitingTime;
}

int main()
{
    int n;
    cin>>n;
    int *t = new int [n];
    for (int i = 0; i < n; i++)
        cin >> t[i];
    cout<<MinTotalWaitingTime(t, n);
    return 0;
}

