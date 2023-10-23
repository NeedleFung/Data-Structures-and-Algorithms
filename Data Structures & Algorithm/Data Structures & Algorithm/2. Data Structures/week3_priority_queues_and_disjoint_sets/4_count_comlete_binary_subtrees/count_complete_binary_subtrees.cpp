#include <iostream>
#include <queue>

// Define a binary tree node structure
struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to check if a binary tree is a complete binary tree
bool isCompleteBinaryTree(TreeNode* root)
{
    // Base case: an empty tree is complete
    if (root == nullptr)
        return true;

    // Initialize a queue for level order traversal
    std::queue<TreeNode*> q;
    q.push(root);

    // Flag to indicate if we've encountered a non-full node
    bool nonFullNode = false;

    // Perform level order traversal
    while (!q.empty())
    {
        TreeNode* current = q.front();
        q.pop();

        // If we encounter a nullptr, set the flag
        if (current == nullptr)
        {
            nonFullNode = true;
        }
        else
        {
            // If we've previously encountered a non-full node,
            // and the current node is not nullptr, the tree is not complete
            if (nonFullNode)
                return false;

            // Otherwise, enqueue the left and right children
            q.push(current->left);
            q.push(current->right);
        }
    }

    // If we reach here, the tree is complete
    return true;
}

// Function to count the number of complete binary subtrees in a binary tree
int countCompleteSubtrees(TreeNode* root)
{
    if (root == nullptr)
        return 0;

    int count = 0;

    // If the current tree is a complete binary tree, increment the count
    if (isCompleteBinaryTree(root))
        count++;

    // Recursively count complete subtrees in the left and right subtrees
    count += countCompleteSubtrees(root->left);
    count += countCompleteSubtrees(root->right);

    return count;
}

int main()
{
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(11);
    root->right->right->left = new TreeNode(12);
    root->right->right->right = new TreeNode(13);

    int numCompleteSubtrees = countCompleteSubtrees(root);
    std::cout << "Number of complete binary subtrees: " << numCompleteSubtrees << std::endl;

    return 0;
}

