#include <iostream>
#include <vector>
using namespace std;

void QuickSort(vector<int> &ages, int left, int right)
{
    if (left < right)
    {
        int i = left;
        int j = right;
        int t = ages[(left + right)/2];
        while (i <= j)
        {
            while (ages[i] < t) i++;
            while (ages[j] > t) j--;
            if (i <= j)
            {
                swap(ages[i], ages[j]);
                i++;
                j--;
            }
        }
        QuickSort(ages, left, j);
        QuickSort(ages, i, right);
    }
}

void PointsCoveredBySegments(vector<int> &ages, int n)
{
    int num = 0;
    vector<int> agesRange(num*2);
    int left = 0;
    while (left < n)
    {
        int l = ages[left];
        int r = ages[left] + 2;
        agesRange.push_back(l);
        num++;
        left++;
        while(left < n and ages[left] <= r)
            left++;
        agesRange.push_back(ages[left - 1]);
    }
    cout<<num<<endl;
    for (int i = 0; i < agesRange.size();)
    {
        cout<<agesRange[i]<<' '<<agesRange[i+1]<<endl;
        i = i+2;
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> ages(n);
    for (int i = 0; i < n; i++)
        cin>> ages[i];
    QuickSort(ages, 0, n-1);
    PointsCoveredBySegments(ages, n);
    return 0;
}
