#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node
{
    int key;
    int left;
    int right;

    Node() : key(0), left(-1), right(-1) {}
    Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool isBST(const vector<Node>& tree, int rootIndex, int minVal, int maxVal)
{
    if (rootIndex == -1)
        return true;
    if (tree[rootIndex].key <= minVal || tree[rootIndex].key >= maxVal)
        return false;
    return isBST(tree, tree[rootIndex].left, minVal, tree[rootIndex].key)
           && isBST(tree, tree[rootIndex].right, tree[rootIndex].key, maxVal);
}

bool IsBinarySearchTree(const vector<Node>& tree)
{
    if (tree.size() == 0)
        return true;
    return isBST(tree, 0, INT_MIN, INT_MAX);
}

int main()
{
    int nodes;
    cin >> nodes;
    vector<Node> tree;
    for (int i = 0; i < nodes; ++i)
    {
        int key, left, right;
        cin >> key >> left >> right;
        tree.push_back(Node(key, left, right));
    }
    if (IsBinarySearchTree(tree))
    {
        cout << "CORRECT" << endl;
    }
    else
    {
        cout << "INCORRECT" << endl;
    }
    return 0;
}
