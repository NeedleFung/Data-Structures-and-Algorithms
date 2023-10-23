#include <iostream>
#include <cstdlib>

int main()
{
    std::cout<<"numbers of integers: ";
    int n;
    std::cin>>n;
    std::cout<<"Range of value of each integer: ";
    int a, b;
    std::cin>>a>>b;
    int distance = b - a;

    for (int i = 1; i <= n; i++)
    {
        std::cout<<rand() % distance + a<<',';
    }
    return 0;
}
