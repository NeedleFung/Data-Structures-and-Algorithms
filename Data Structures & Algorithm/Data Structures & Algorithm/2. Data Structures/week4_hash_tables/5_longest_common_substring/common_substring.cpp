#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;
const int p = 31;
const int MOD = 1e9 + 7;

struct Answer
{
    size_t i, j, len;
};

/*
Answer solve(const string &s, const string &t)
{
    Answer ans = {0, 0, 0};
    for (size_t i = 0; i < s.size(); i++)
        for (size_t j = 0; j < t.size(); j++)
            for (size_t len = 0; i + len <= s.size() && j + len <= t.size(); len++)
                if (len > ans.len && s.substr(i, len) == t.substr(j, len))
                    ans = {i, j, len};
    return ans;
}
*/

size_t computeHash(const string& s)
{
    size_t hashValue = 0;
    size_t p_pow = 1;
    for (char c : s)
    {
        hashValue = (hashValue + (c - 'a' + 1) * p_pow) % MOD;
        p_pow = (p_pow * p) % MOD;
    }
    return hashValue;
}

Answer solve(const string& s, const string& t)
{
    int left = 0;
    int right = min(s.size(), t.size());
    pair<int, int> lcs = {-1, -1};

    while (left <= right) {
        int mid = left + (right - left) / 2;
        bool found = false;
        long long hashS = 0;
        long long p_pow = 1;

        for (int i = 0; i < mid; ++i) {
            hashS = (hashS + (s[i] - 'a' + 1) * p_pow) % MOD;
            p_pow = (p_pow * p) % MOD;
        }

        vector<long long> hashesT;
        long long hashT = 0;

        for (int i = 0; i < t.size(); ++i) {
            hashT = (hashT + (t[i] - 'a' + 1) * p_pow) % MOD;
            if (i >= mid - 1) {
                hashesT.push_back(hashT);
                hashT = (hashT - (t[i - mid + 1] - 'a' + 1) * p_pow + MOD) % MOD;
            }
        }

        for (int i = 0; i + mid <= s.size(); ++i) {
            auto it = find(hashesT.begin(), hashesT.end(), hashS);
            if (it != hashesT.end()) {
                lcs = {i, distance(hashesT.begin(), it)};
                found = true;
                break;
            }

            if (i + mid < s.size()) {
                hashS = (hashS - (s[i] - 'a' + 1) + MOD) % MOD;
                hashS = (hashS * p_pow) % MOD;
                hashS = (hashS + (s[i + mid] - 'a' + 1)) % MOD;
            }
        }

        if (found) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return {lcs.first, lcs.second, lcs.first != -1 ? min(s.size() - lcs.first, t.size() - lcs.second) : 0};
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    string s, t;
    while (cin >> s >> t)
    {
        if (isdigit(s[0]))
        {
            cout<< "\r";
            break;
        }
        auto ans = solve(s, t);
        cout << ans.i << " " << ans.j << " " << ans.len << "\n";
    }
    return 0;
}
