#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

public:
    TreeNode()
    {
        val = 0;
        left = nullptr;
        right = nullptr;
    }

public:
    TreeNode(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }

public:
    TreeNode(int x, TreeNode *l1, TreeNode *r1)
    {
        val = x;
        left = l1;
        right = r1;
    }
};

int maxDepth(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return max(leftDepth, rightDepth) + 1;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(8);

    cout << maxDepth(root);

    return 0;
}