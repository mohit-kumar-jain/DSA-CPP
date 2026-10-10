#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

// Brute. T.C -> O(N*N), S.C -> O(Height of bt).
// int findMaxDownwardPath(TreeNode *root)
// {
//     if (root == nullptr)
//     {
//         return 0;
//     }
//     int leftGain = max(0,findMaxDownwardPath(root->left));
//     int rightGain = max(0,findMaxDownwardPath(root->right));
//     return root->val + max(leftGain,rightGain);
// }
// int maxPathSum(TreeNode *root)
// {
//     if (root == nullptr)
//     {
//         return INT_MIN;
//     }
//     int leftContribution = max(0,findMaxDownwardPath(root->left));
//     int rightContribution = max(0,findMaxDownwardPath(root->right));
//     int currentPath =root->val + leftContribution + rightContribution;
//     int leftBest = root->left? maxPathSum(root->left): INT_MIN;
//     int rightBest = root->right? maxPathSum(root->right): INT_MIN;
//     return max({currentPath,leftBest,rightBest});
// }

// Optimal. T.C -> O(N), S.C -> O(H).
int findMaxGain(TreeNode *root,int &maxSum)
{
    if (root == nullptr)
    {
        return 0;
    }
    int leftGain = max(0,findMaxGain(root->left, maxSum));
    int rightGain = max(0,findMaxGain(root->right, maxSum));
    int currentPath =root->val + leftGain + rightGain;
    maxSum = max(maxSum,currentPath);
    return root->val + max(leftGain,rightGain);
}

int maxPathSum(TreeNode *root)
{
    int maxSum = INT_MIN;
    findMaxGain(root, maxSum);
    return maxSum;
}

int main()
{
    TreeNode *root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << maxPathSum(root) << endl;
    return 0;
}