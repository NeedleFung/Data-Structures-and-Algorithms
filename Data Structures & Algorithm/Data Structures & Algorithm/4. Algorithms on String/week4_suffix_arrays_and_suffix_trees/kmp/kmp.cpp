#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::string;
using std::vector;
//Knuth-Morris-Pratt Algorithm

vector<int> compute_prefix(const string& str) {
    int n = str.length();
    vector<int> s(n);
    s[0] = 0;
    for (int i = 1, border = 0; i < n; ++i) {
        while (border > 0 && str[i] != str[border])
            border = s[border - 1];
        if (str[i] == str[border])
            border++;
        else border = 0;
        s[i] = border;
    }
    return s;
}

vector<int> find_pattern(const string& pattern, const string& text) {
    vector<int> result;
    const string& str = pattern + '$' + text;
    int m = pattern.length(), n = str.length();
    vector<int> s = compute_prefix(str);
    for (int i = m + 1; i < n; ++i)
        if (s[i] == m)
            result.push_back(i - 2 * m);
    return result;
}

int main() {
    string pattern, text;
    cin >> pattern;
    cin >> text;
    vector<int> result = find_pattern(pattern, text);
    for (int i = 0; i < result.size(); ++i) {
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}
