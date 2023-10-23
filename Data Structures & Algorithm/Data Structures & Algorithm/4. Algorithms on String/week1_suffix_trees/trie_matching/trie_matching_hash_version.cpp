#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

using std::string;
using std::vector;
const long long prime = 1e7 + 7;

struct Data {
    string text;
    vector<string> patterns;
};

Data read_input() {
    Data data;
    std::cin >> data.text;
    int n;
    std::cin >> n;
    data.patterns.resize(n);
    for (int i = 1; i <= n; ++i)
        std::cin >> data.patterns[i - 1];
    return data;
}

void print_occurrences(const vector<int>& output) {
    for (int i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
}

long long polyHash(const string& str, long long& x) {
    long long hashValue = 0;
    long long x_pow = 1;

    for (int i = 0; i < str.length(); ++i) {
        long long charValue = str[i];
        hashValue = (((hashValue + (charValue * x_pow) % prime) % prime) + prime) % prime;
        x_pow = (x_pow * x) % prime;
    }

    return hashValue;
}

vector<long long> precomputeHash(const string& pattern, const string& text, long long& x) {
    int m = pattern.length(), n = text.length();
    vector<long long> HashMap(n - m + 1);
    string subStr = text.substr(n - m, m);
    HashMap[n - m] = polyHash(subStr, x);
    long long y = 1; //pow(x, m);
    for (int i = 1; i <= m; ++i)
        y = (y*x) % prime;
    for (int i = n - m - 1; i >= 0; --i)
        HashMap[i] = (((x*HashMap[i + 1] + text[i] - y*text[i + m]) % prime) + prime) % prime;
    return HashMap;
}

vector<int> RabinKarp(const Data& input) {
    const string& text = input.text;
    int n = text.length();
    vector<int> ans;
    for (auto& pattern : input.patterns) {
        int m = pattern.length();
        if (m > n) continue;
        long long x = prime / 2;
        long long patternHash = polyHash(pattern, x);
        vector<long long> HashMap = precomputeHash(pattern, text, x);
        for (int i = 0; i < n - m + 1; ++i) {
            if (patternHash != HashMap[i]) continue;
            if (text.substr(i, m) == pattern)
                ans.push_back(i);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(RabinKarp(read_input()));
    return 0;
}


