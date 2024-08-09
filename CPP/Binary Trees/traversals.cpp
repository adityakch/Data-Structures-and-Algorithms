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

void inorderTraversal(TreeNode *root, vector<int> &res)
{
    if (!root)
        return;

    inorderTraversal(root->left, res);
    res.emplace_back(root->val);
    inorderTraversal(root->right, res);
}

void preorderTraversal(TreeNode *root, vector<int> &res)
{
    if (!root)
        return;

    res.emplace_back(root->val);
    preorderTraversal(root->left, res);
    preorderTraversal(root->right, res);
}

void postorderTraversal(TreeNode *root, vector<int> &res)
{
    if (!root)
        return;

    postorderTraversal(root->left, res);
    postorderTraversal(root->right, res);
    res.emplace_back(root->val);
}

vector<vector<int>> levelorderTraversal(TreeNode *root)
{
    if (!root)
        return {};

    queue<TreeNode *> q;
    q.push(root);

    vector<vector<int>> res;

    while (!q.empty())
    {
        int len = q.size();
        vector<int> curLvl;

        for (int i = 0; i < len; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            curLvl.push_back(node->val);

            if (node->left)
            {
                q.push(node->left);
            }

            if (node->right)
            {
                q.push(node->right);
            }
        }
        res.push_back(curLvl);
    }

    return res;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    // root->right->right = new TreeNode(7);

    vector<int> res;

    // inorderTraversal(root, res);
    // preorderTraversal(root, res);
    postorderTraversal(root, res);

    vector<vector<int>> ans = levelorderTraversal(root);

    cout << "[ ";
    for (auto list : ans)
    {
        cout << "[ ";
        for (auto i : list)
        {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "]" << endl;

    return 0;
}