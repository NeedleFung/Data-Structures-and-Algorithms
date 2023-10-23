#include <bits/stdc++.h>
using namespace std;

int DPMoneyChange(int money, vector<int> &coins)
{
    vector<int> MinNumCoins(money + 1, 0);
    MinNumCoins[0] = 0;
    for (int m = 1; m <= money; m++)
    {
        MinNumCoins[m] = money;
        for (int i = 0; i < coins.size(); i++)
            if (m >= coins[i])
            {
                int NumCoins = MinNumCoins[m - coins[i]] + 1;
                if (NumCoins < MinNumCoins[m])
                    MinNumCoins[m] = NumCoins;
            }
    }
    for (int i : MinNumCoins)
        std::cout<<i<<' ';
    std::cout<<std::endl;
    return MinNumCoins[money];
}

int main()
{
    int money;
    cin>>money;
    vector<int> coins = {1, 3, 4};
    cout<<DPMoneyChange(money, coins);
    return 0;
}
