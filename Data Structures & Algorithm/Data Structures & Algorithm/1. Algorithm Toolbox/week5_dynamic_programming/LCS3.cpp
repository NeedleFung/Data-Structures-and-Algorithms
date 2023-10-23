#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>

//Recursion Implementation
int dp[100][100][100];
int RecursionLCS3(std::vector<long long> &seq1, std::vector<long long> &seq2, std::vector<long long> &seq3, int l, int m, int n)
{
   	if(l == -1 || m == -1 || n == -1)
		return 0;
	if(dp[l][m][n] != -1)
		return dp[l][m][n];

	if(seq1[l] == seq2[m] && seq2[m] == seq3[n])
		return dp[l][m][n] = 1 + RecursionLCS3(seq1, seq2, seq3, l-1, m-1, n-1);
	else
		return dp[l][m][n] = std::max(std::max(RecursionLCS3(seq1, seq2, seq3, l-1, m, n), RecursionLCS3(seq1, seq2, seq3, l, m-1, n)), RecursionLCS3(seq1, seq2, seq3, l, m, n-1));
}

//Iteration Implementation
int IterationLCS3(std::vector<long long> &seq1, std::vector<long long> &seq2, std::vector<long long> &seq3)
{
    int l = seq1.size();
    int m = seq2.size();
    int n = seq3.size();

    std::vector<std::vector<std::vector<int>>> dp(l + 1, std::vector<std::vector<int>>(m + 1, std::vector<int>(n + 1, 0)));

    for (int i = 1; i <= l; i++)
        for (int j = 1; j <= m; j++)
            for(int k = 1; k <= n; k++)
            {
                if (seq1[i-1] == seq2[j-1] && seq1[i-1] == seq3[k-1])
                    dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
                else
                    dp[i][j][k] = std::max(std::max(dp[i-1][j][k], dp[i][j-1][k]), dp[i][j][k-1]);
            }
    return dp[l][m][n];
}

int main()
{
    /*
    while (true)
    {
        int l = rand() % 99 + 1;
        int m = rand() % 99 + 1;
        int n = rand() % 99 + 1;

        std::cout<<l<<'\n';
        std::vector<long long> seq1(l, 0);
        for (int i = 1; i < l; i++)
            seq1[i] = rand() % 1000;
        for (int i = 0; i < l; i++)
            std::cout<<seq1[i]<<' ';
        std::cout<<'\n';

        std::cout<<m<<'\n';
        std::vector<long long> seq2(m, 0);
        for (int i = 1; i < m; i++)
            seq2[i] = rand() % 1000;
        for (int i = 0; i < m; i++)
            std::cout<<seq2[i]<<' ';
        std::cout<<'\n';

        std::cout<<n<<'\n';
        std::vector<long long> seq3(n, 0);
        for (int i = 0; i < n; i++)
            seq3[i] = rand() % 1000;
        for (int i = 0; i < n; i++)
            std::cout<<seq3[i]<<' ';
        std::cout<<'\n';

        memset(dp, -1, sizeof(dp));
        auto res1 = IterationLCS3(seq1, seq2, seq3);
        auto res2 = RecursionLCS3(seq1, seq2, seq3, l - 1, m - 1, n - 1);
        if (res1 != res2)
        {
            std::cout<<"Wrong answer: "<<res1<<" != "<<res2<<'\n';
            break;
        }
        else
            std::cout<<"OK: "<<res1<<" == "<<res2<<"\n\n";
    }
    */
    int l, m, n;

    std::cin>>l;
    std::vector<long long> seq1(l, 0);
    for (int i = 0; i < l; i++)
        std::cin>>seq1[i];

    std::cin>>m;
    std::vector<long long> seq2(m, 0);
    for (int i = 0; i < m; i++)
        std::cin>>seq2[i];

    std::cin>>n;
    std::vector<long long> seq3(n, 0);
    for (int i = 0; i < n; i++)
        std::cin>>seq3[i];

    memset(dp, -1, sizeof(dp));
    std::cout<<IterationLCS3(seq1, seq2, seq3);
    return 0;
}
