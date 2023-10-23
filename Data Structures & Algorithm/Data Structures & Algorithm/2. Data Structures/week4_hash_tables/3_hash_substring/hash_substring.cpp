#include <iostream>
#include <string>
#include <vector>
#include <random>

using std::string;
const long long prime = 1e7 + 7;

struct Data
{
    string pattern, text;
};

Data read_input()
{
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const std::vector<long long>& output)
{
    for (long long i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
}

long long polyHash(const string& str, long long& x)
{
    long long hashValue = 0;
    long long x_pow = 1;

    for (long long i = 0; i < str.length(); ++i)
    {
        long long charValue = str[i];
        hashValue = (((hashValue + (charValue * x_pow) % prime) % prime) + prime) % prime;
        x_pow = (x_pow * x) % prime;
    }

    return hashValue;
}

std::vector<long long> precomputeHash(const Data& input, long long& x)
{
    const string& pattern = input.pattern, text = input.text;
    long long m = pattern.length(), n = text.length();
    std::vector<long long> HashMap(n - m + 1);
    string subStr = text.substr(n - m, m);
    HashMap[n - m] = polyHash(subStr, x);
    long long y = 1; //pow(x, m);
    for (long long i = 1; i <= m; ++i)
        y = (y*x) % prime;
    for (long long i = n - m - 1; i >= 0; --i)
    {
        HashMap[i] = (((x*HashMap[i + 1] + text[i] - y*text[i + m]) % prime) + prime) % prime;
    }
    return HashMap;
}

std::vector<long long> RabinKarp(const Data& input)
{
    const string& pattern = input.pattern, text = input.text;
    long long m = pattern.length(), n = text.length();
    std::vector<long long> ans;
    long long x = prime / 2;
    long long patternHash = polyHash(pattern, x);
    std::vector<long long> HashMap = precomputeHash(input, x);
    for (long long i = 0; i < n - m + 1; i++)
    {
        if (patternHash != HashMap[i]) continue;
        if (text.substr(i, m) == pattern)
            ans.push_back(i);
    }
    return ans;
}

/*
std::vector<long long> get_occurrences(const Data& input)
{
    const string& s = input.pattern, t = input.text;
    std::vector<long long> ans;
    for (long long i = 0; i + s.size() <= t.size(); ++i)
        if (t.substr(i, s.size()) == s)
            ans.push_back(i);
    return ans;
}
*/

int main()
{
    std::ios_base::sync_with_stdio(false);
    //print_occurrences(get_occurrences(read_input()));
    print_occurrences(RabinKarp(read_input()));
    return 0;
}


