#include <string>
#include <iostream>
#include <vector>
#include <map>

using std::map;
using std::vector;
using std::string;

typedef map<char, int> edges;
typedef vector<edges> trie;

trie build_trie(vector<string> & patterns) {
    trie t(1);
    for (auto& pattern : patterns) {
        int currNode = 0;
        for (auto& symbol : pattern) {
            if (t[currNode].find(symbol) != t[currNode].end())
                currNode = t[currNode][symbol];
            else {
                int newNode = t.size();
                t[currNode][symbol] = newNode;
                edges newEdge;
                t.push_back(newEdge);
                currNode = newNode;
            }
        }
    }
    return t;
}

int main()
{
    size_t n;
    std::cin >> n;
    vector<string> patterns;
    for (size_t i = 0; i < n; i++) {
        string s;
        std::cin >> s;
        patterns.push_back(s);
    }

    trie t = build_trie(patterns);
    for (size_t i = 0; i < t.size(); ++i) {
        for (const auto & j : t[i]) {
            std::cout << i << "->" << j.second << ":" << j.first << "\n";
        }
    }

    return 0;
}
