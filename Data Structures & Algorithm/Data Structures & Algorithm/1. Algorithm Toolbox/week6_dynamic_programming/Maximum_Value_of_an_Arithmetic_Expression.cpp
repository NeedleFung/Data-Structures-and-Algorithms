#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

std::pair<long long, long long> MaxAndMin(int i, int j, std::vector<std::pair<char, int>>& OPnVAL, std::vector<std::vector<long long>>& Max, std::vector<std::vector<long long>>& Min)
{
    long long MAX = LLONG_MIN;
    long long MIN = LLONG_MAX;

    for (int k = i; k <= j - 1; k++)
    {
        char op = OPnVAL[k + 1].first;
        long long a, b, c, d;
        switch (op)
        {
        case '+':
            a = Max[i][k] + Max[k + 1][j];
            b = Max[i][k] + Min[k + 1][j];
            c = Min[i][k] + Max[k + 1][j];
            d = Min[i][k] + Min[k + 1][j];
            break;
        case '-':
            a = Max[i][k] - Max[k + 1][j];
            b = Max[i][k] - Min[k + 1][j];
            c = Min[i][k] - Max[k + 1][j];
            d = Min[i][k] - Min[k + 1][j];
            break;
        case '*':
            a = Max[i][k] * Max[k + 1][j];
            b = Max[i][k] * Min[k + 1][j];
            c = Min[i][k] * Max[k + 1][j];
            d = Min[i][k] * Min[k + 1][j];
            break;
        }
        MAX = std::max({MAX, a, b, c, d});
        MIN = std::min({MIN, a, b, c, d});
    }

    return std::make_pair(MAX, MIN);
}

long long Parentheses (std::vector<std::pair<char, int>>& OPnVAL, std::string Expression)
{
    int n = Expression.size() / 2;
    std::vector<std::vector<long long>> Max(n, std::vector<long long> (n, 0));
    std::vector<std::vector<long long>> Min(n, std::vector<long long> (n, 0));

    for (int i = 0; i < n; i++)
    {
        Max[i][i] = OPnVAL[i].second;
        Min[i][i] = OPnVAL[i].second;
    }

    int j = 0;
    for (int s = 1; s <= n - 1; s++)
    {
        for (int i = 0; i < n - s; i++)
        {
            j = i + s;
            std::pair<long long, long long> Value = MaxAndMin(i, j, OPnVAL, Max, Min);
            Max[i][j] = Value.first;
            Min[i][j] = Value.second;
        }
    }

    return Max[0][n - 1];
}

int main()
{
    std::string Expression;
    std::cin>>Expression;
    std::vector<std::pair<char, int>> OPnVAL;
    OPnVAL.push_back(std::make_pair(' ', 0));

    if (Expression[0] - '0' >= 0)
        Expression = '+' + Expression;

    int j = 0;
    for (int i = 0; i < Expression.length(); i++)
    {
        if (Expression[i] - '0' < 0)
            OPnVAL[j].first = Expression[i];
        if (Expression[i] - '0' >= 0)
            OPnVAL[j].second += int(Expression[i] - '0');
        if (Expression[i + 1] - '0' < 0)
        {
            j++;
            OPnVAL.push_back(std::make_pair(' ', 0));
        }
        else OPnVAL[j].second = OPnVAL[j].second * 10;
    }
    OPnVAL.pop_back();

    std::cout<<Parentheses(OPnVAL, Expression);

    return 0;
}
