#include <iostream>
#include <vector>
#include <algorithm>

int KnapsackWithRepetitions(int Weight, std::vector<int> &weights)
{
    std::vector<int> Value(Weight + 1, 0);
    for (int w = 1; w <= Weight; w++)
    {
        for (int i = 0; i < weights.size(); i++)
            if (w >= weights[i])
                Value[w] = std::max(Value[w], Value[w - weights[i]] + weights[i]);
//weights[i] is actually value of items[i], but the problem doesn't mention the value, so we assign the value of items as the weights of them.
    }
    for (int i : Value)
        std::cout<<i<<' ';
    std::cout<<std::endl;
    return Value[Weight];
}

int main()
{
    int Weight, n;
    std::cin>>Weight>>n;
    std::vector<int> weights(n);
    for (int i = 0; i < n; i++)
        std::cin>>weights[i];
    std::cout<<KnapsackWithRepetitions(Weight, weights);
    return 0;
}
