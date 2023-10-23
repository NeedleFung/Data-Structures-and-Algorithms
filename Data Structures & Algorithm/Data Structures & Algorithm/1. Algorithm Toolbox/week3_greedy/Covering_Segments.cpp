#include <iostream>
#include <vector>
#include <algorithm>

void CollectSignatures(std::vector<std::vector<long long>>& Segments, int n)
{
    sort(Segments.begin(), Segments.end(), [](const auto& a, const auto& b)
         {
             return a[1] < b[1];
         });
    /*
    const auto& it = (*std::min_element(Segments.begin(), Segments.end(), [](const auto& a, const auto& b)
                                      {
                                          return a[1] < b[1];
                                      }))[1];
    */
    long long curr = Segments[0][1];
    int i = 1;
    int count = 0;
    std::vector<int> ans;
    while (i < n)
    {
        if (curr < Segments[i][0])
        {
            count++;
            ans.push_back(curr);
            curr = Segments[i][1];
        }
        i++;
    }
    if (i == n)
        count++;
    ans.push_back(curr);

    std::cout<<count<<'\n';
    for (auto& i : ans)
        std::cout<<i<<' ';
}

int main()
{
    int n;
    std::cin>>n;

    std::vector<std::vector<long long>> Segments(n, std::vector<long long>(2, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            std::cin>>Segments[i][j];

    CollectSignatures(Segments, n);
    return 0;
}
