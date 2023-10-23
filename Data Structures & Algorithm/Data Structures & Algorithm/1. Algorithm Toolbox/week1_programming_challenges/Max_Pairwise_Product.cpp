#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

/*long long QuickSort(vector<int> &numbers, int left, int right)
{
    if (left < right)
    {
        int i = left;
        int j = right;
        int k = (left + right)/2;
        int t = numbers[k];
        while (i <= j)
        {
            while (numbers[i] > t) i++;
            while (numbers[j] < t) j--;
            if (i <= j)
            {
                swap(numbers[i], numbers[j]);
                i++;
                j--;
            }
        }
        QuickSort(numbers, left, j);
        QuickSort(numbers, i, right);
    }
    return (long long)numbers[0]*numbers[1];
}*/
long long Max_Pairwise_Product(const vector<int> &numbers)
{
    int n = numbers.size();
    int max1_index = 0;
    for (int i = 1; i < n; i++)
        if (numbers[i] > numbers[max1_index]) max1_index = i;

    int max2_index = -1;
    for (int j = 0; j < n; j++)
        if ((j != max1_index && max2_index == -1) || (numbers[j] > numbers[max2_index] && j != max1_index)) max2_index = j;
    return(long long)numbers[max1_index]*numbers[max2_index];
}
int main()
{
    /*while (true)
    {
        int n = rand() % 10 +2;
        cout<<n<<endl;
        vector<int> a;
        for (int i = 0; i < n; i++)
            a.push_back(rand() % 100000);
        for (int i = 0; i < n; i++)
            cout<<a[i]<<" ";
        long long res1 = Max_Pairwise_Product(a);
        long long res2 = QuickSort(a, 0, n-1);
        if (res1 != res2)
        {
            cout<<"Wrong answer: "<<res1<<" != "<<res2<<endl;
            break;
        }
        else cout<<"OK\n\n";
    }*/
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }
    cout<<Max_Pairwise_Product(numbers)<<endl;
    //cout<<QuickSort(numbers, 0, n-1)<<endl;

    return 0;
}

