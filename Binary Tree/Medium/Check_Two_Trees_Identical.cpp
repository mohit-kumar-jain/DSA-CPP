#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value)
    {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

// 1.  T.C -> O(N), S.C -> O(height of tree).
// bool isSameTree(TreeNode *p, TreeNode *q)
// {
//     if (p == nullptr && q == nullptr)
//     {
//         return true;
//     }
//     if (p == nullptr || q == nullptr)
//     {
//         return false;
//     }
//     if (p->val != q->val)
//     {
//         return false;
//     }
//     return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
// }

// 2. T.C -> O(N), S.C -> O(width of tree).
bool isSameTree(TreeNode *p, TreeNode *q)
{
    queue<pair<TreeNode *, TreeNode *>> qNodes;
    qNodes.push({p, q});
    while (!qNodes.empty())
    {
        pair<TreeNode*, TreeNode*> temp = qNodes.front();
        qNodes.pop();
        TreeNode* nodeP = temp.first;
        TreeNode* nodeQ = temp.second;
        if (nodeP == nullptr && nodeQ == nullptr)
        {
            continue;
        }
        if (nodeP == nullptr || nodeQ == nullptr)
        {
            return false;
        }
        if (nodeP->val != nodeQ->val)
        {
            return false;
        }
        qNodes.push({nodeP->left, nodeQ->left});
        qNodes.push({nodeP->right, nodeQ->right});
    }
    return true;
}

// 3.  T.C -> O(N), S.C -> O(height of tree).
// bool isSameTree(TreeNode *p, TreeNode *q)
// {
//     stack<pair<TreeNode*, TreeNode*>> st;
//     st.push({p, q});
//     while(!st.empty())
//     {
//         pair<TreeNode*, TreeNode*> temp = st.top();
//         st.pop();
//         TreeNode* nodeP = temp.first;
//         TreeNode* nodeQ = temp.second;
//         if(nodeP == nullptr && nodeQ == nullptr)
//             continue;
//         if(nodeP == nullptr || nodeQ == nullptr)
//             return false;
//         if(nodeP->val != nodeQ->val)
//             return false;
//         st.push({nodeP->right, nodeQ->right});
//         st.push({nodeP->left, nodeQ->left});
//     }
//     return true;
// }

int main()
{
    TreeNode *p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode *q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    cout << (isSameTree(p, q) ? "True" : "False") << endl;

    return 0;
}