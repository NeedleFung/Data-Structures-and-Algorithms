#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

vector<int> SortCharacters(const string& str) {
    int S = str.length();
    vector<int> order(S);
    vector<int> count(95, 0);
    for (int i = 0; i < S; ++i)
        count[str[i] - '!']++;
    for (int j = 1; j < 95; ++j)
        count[j] += count[j - 1];
    for (int i = S - 1; i >= 0; --i) {
        int c = str[i] - '!';
        count[c]--;
        order[count[c]] = i;
    }
    return order;
}

vector<int> ComputeCharClasses(const string& str, vector<int>& order) {
    int S = str.length();
    vector<int> class_(S);
    class_[order[0]] = 0;
    for (int i = 1; i < S; ++i) {
        if (str[order[i]] != str[order[i - 1]])
            class_[order[i]] = class_[order[i - 1]] + 1;
        else
            class_[order[i]] = class_[order[i - 1]];
    }
    return class_;
}

vector<int> SortDoubled(const string& str, int L, vector<int>& order, vector<int>& class_) {
    int S = str.length();
    vector<int> newOrder(S);
    vector<int> count(S, 0);
    for (int i = 0; i < S; ++i)
        count[class_[i]]++;
    for (int j = 1; j < S; ++j)
        count[j] += count[j - 1];
    for (int i = S - 1; i >= 0; --i) {
        int start = (order[i] - L + S) % S;
        int cl = class_[start];
        count[cl]--;
        newOrder[count[cl]] = start;
    }
    for (auto i : newOrder)
        cout<<i<<' ';
    cout<<endl;
    return newOrder;
}

vector<int> UpdateClasses(vector<int>& order, vector<int>& class_, int L) {
    int n = order.size();
    vector<int> newClass(n);
    newClass[order[0]] = 0;
    for (int i = 1; i < n; ++i) {
        int curr = order[i], prev = order[i - 1];
        int mid = curr + L, midPrev = (prev + L) % n;
        if (class_[curr] != class_[prev] || class_[mid] != class_[midPrev])
            newClass[curr] = newClass[prev] + 1;
        else
            newClass[curr] = newClass[prev];
    }
    for (auto i : newClass)
        cout<<i<<' ';
    cout<<endl;
    return newClass;
}

vector<int> BuildSuffixArray(const string& text) {
    int S = text.length();
    vector<int> order = SortCharacters(text);
    vector<int> class_ = ComputeCharClasses(text, order);
    int L = 1;
    while (L < S) {
        order = SortDoubled(text, L, order, class_);
        class_ = UpdateClasses(order, class_, L);
        L *= 2;
    }
    return order;
}

int main() {
    string text;
    cin >> text;
    vector<int> suffix_array = BuildSuffixArray(text);
    for (int i = 0; i < suffix_array.size(); ++i) {
        cout << suffix_array[i] << ' ';
    }
    cout << endl;
    return 0;
}
