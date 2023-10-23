#include <iostream>
#include <vector>
#include <algorithm>

int KnapsackWithoutRepetitions(int Weight, std::vector<int> &weights)
{
    std::vector<std::vector<int>> Value(Weight + 1, std::vector<int> (weights.size() + 1, 0));

    for (int i = 1; i <= weights.size(); i++)
    {
        for (int w = 1; w <= Weight; w++)
        {
            Value[w][i] = Value[w][i - 1];
            if (w >= weights[i - 1])
                Value[w][i] = std::max(Value[w][i], Value[w - weights[i - 1]][i - 1] + weights[i - 1]);
//weights[i] is actually value of items[i], but the problem doesn't mention the value, so we assign the value of items as the weights of them.
        }
    }
/*
    for (const auto& i : Value)
    {
        for (auto j : i)
            std::cout<<j<<' ';
        std::cout<<std::endl;
    }
*/
    return Value[Weight][weights.size()];
}

int main()
{
    int Weight, n;
    std::cin>>Weight>>n;

    std::vector<int> weights(n);
    for (int i = 0; i < n; i++)
        std::cin>>weights[i];

    std::cout<<KnapsackWithoutRepetitions(Weight, weights);
    return 0;
}

