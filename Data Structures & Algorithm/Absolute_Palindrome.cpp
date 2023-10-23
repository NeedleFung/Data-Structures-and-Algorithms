#include <iostream>
#include <string>

long long findY(long long x)
{
    std::string numX = std::to_string(x);
    if (numX[0] < '9')
    {
        std::string total1(numX.length(), numX[0]);
        long long y1 = std::stoll(total1) - x;
        std::string total2(numX.length(), numX[0] + 1);
        long long y2 = std::stoll(total2) - x;

        if (y1 > 0)
            return std::min(y1, y2);
        else return y2;
    }
    std::string total(numX.length(), numX[0]);
    return std::stoll(total) - x;
}

int main()
{
    long long x;
    std::cin >> x;
    std::cout << findY(x) << std::endl;

    return 0;
}
