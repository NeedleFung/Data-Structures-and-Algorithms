#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int EditDistance(std::string word1, std::string word2)
{
    const int m = word1.length();
    const int n = word2.length();
    if (word1 == "") return word2.size();
    if (word2 == "") return word1.size();

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
        dp[i][0] = i;
    for (int j = 1; j <= n; j++)
        dp[0][j] = j;

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = std::min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
    return dp[m][n];
}

int main()
{
    std::string word1, word2;
    std::cin>>word1>>word2;
    int ans = EditDistance(word1, word2);
    std::cout<<ans;
    return 0;
}
