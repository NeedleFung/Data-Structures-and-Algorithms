#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>

//Iteration Implementation
int IterationLCS2(std::vector<long long> &seq1, std::vector<long long> &seq2)
{
    int m = seq1.size();
    int n = seq2.size();

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    for(int i = 0; i <= m; i++)
        dp[i][0] = 0;
    for(int i = 0; i <= n; i++)
        dp[0][i] = 0;

    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            if(seq1[i-1] == seq2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
    return dp[m][n];
    /*
    std::vector<char> ans;
    while(m > 0 && n > 0)
    {
        if(seq1[m-1] == seq2[n-1])
        {
            ans.push_back(seq1[m-1]);
            m--;
            n--;
        }
        else
        {
            if(dp[m-1][n] > dp[m][n-1])
                m--;
            else
                n--;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
    */
}

//Recursion Implementation
int dp[100][100];
int RecursionLCS2(std::vector<long long> &seq1, std::vector<long long> &seq2, int x, int y)
{
    if (x == -1 || y == -1)
        return 0;
    if (dp[x][y] != -1)
        return dp[x][y];

    if (seq1[x] == seq2[y])
        return dp[x][y] = 1 + RecursionLCS2(seq1, seq2, x - 1, y - 1);
    else
        return dp[x][y] = std::max(RecursionLCS2(seq1, seq2, x - 1, y), RecursionLCS2(seq1, seq2, x, y - 1));
}

int main()
{
/*
    while (true)
    {
        int m = rand() % 10 + 1;
        int n = rand() % 10 + 1;

        std::cout<<m<<'\n';
        std::vector<long long> seq1(m, 0);
        for (int i = 1; i < m; i++)
            seq1[i] = rand() % 20;
        for (int i = 0; i < m; i++)
            std::cout<<seq1[i]<<' ';
        std::cout<<'\n';

        std::cout<<n<<'\n';
        std::vector<long long> seq2(n, 0);
        for (int i = 0; i < n; i++)
            seq2[i] = rand() % 20;
        for (int i = 0; i < n; i++)
            std::cout<<seq2[i]<<' ';
        std::cout<<'\n';

        auto res1 = IterationLCS2(seq1, seq2);
        memset(dp, -1, sizeof(dp));
        auto res2 = RecursionLCS2(seq1, seq2, m - 1, n - 1);
        if (res1 != res2)
        {
            std::cout<<"Wrong answer: "<<res1<<" != "<<res2<<'\n';
            break;
        }
        else
            std::cout<<"OK: "<<res1<<" == "<<res2<<"\n\n";
    }
*/
    int m, n;
    std::cin>>m;
    std::vector<long long> seq1(m, 0);
    for (int i = 0; i < m; i++)
        std::cin>>seq1[i];
    std::cin>>n;
    std::vector<long long> seq2(n, 0);
    for (int i = 0; i < n; i++)
        std::cin>>seq2[i];
    memset(dp, -1, sizeof(dp));
    auto res = RecursionLCS2(seq1, seq2, m - 1, n - 1);
    std::cout<<res;
    return 0;
}
