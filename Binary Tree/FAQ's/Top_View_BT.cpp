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

struct Entry
{
    int hd;
    int level;
    int order;
    int value;
};
// T.C -> O(Nlog N), S.C -> O(N).
// vector<int> topView(TreeNode *root)
// {
//     if (root == nullptr)
//     {
//         return {};
//     }
//     vector<Entry> nodes;
//     queue<tuple<TreeNode *, int, int>> q;
//     q.push(make_tuple(root, 0, 0));
//     int order = 0;
//     while (!q.empty())
//     {
//         tuple<TreeNode *, int, int> temp = q.front();
//         q.pop();
//         TreeNode *node = get<0>(temp);
//         int hd = get<1>(temp);
//         int level = get<2>(temp);
//         nodes.push_back({hd, level, order++, node->val});
//         if (node->left != nullptr)
//         {
//             q.push(make_tuple(node->left, hd - 1, level + 1));
//         }
//         if (node->right != nullptr)
//         {
//             q.push(make_tuple(node->right, hd + 1, level + 1));
//         }
//     }
//     sort(nodes.begin(), nodes.end(),
//          [](const Entry &a, const Entry &b)
//          {
//             if (a.hd != b.hd)
//             {
//                 return a.hd < b.hd;
//             }
//             if (a.level != b.level)
//             {
//                 return a.level < b.level;
//             }
//             return a.order < b.order;
//          });
//     vector<int> answer;
//     int previousHD = INT_MIN;
//     for (const Entry &entry : nodes)
//     {
//         if (entry.hd != previousHD)
//         {
//             answer.push_back(entry.value);
//             previousHD = entry.hd;
//         }
//     }
//     return answer;
// }


void dfs(TreeNode *node, int hd, int level, map<int, pair<int, int>> &topNodes)
{
    if (node == nullptr)
    {
        return;
    }
    auto it = topNodes.find(hd);
    if (
        it == topNodes.end() || level < it->second.first)
    {
        topNodes[hd] = {level, node->val};
    }
    dfs(node->left, hd - 1, level + 1, topNodes);
    dfs(node->right, hd + 1, level + 1, topNodes);
}

// T.C -> O(Nlog N), S.C -> O(log N).
vector<int> topView(TreeNode *root)
{
    if (root == nullptr)
    {
        return {};
    }
    map<int, pair<int, int>> topNodes;
    dfs(root, 0, 0, topNodes);
    vector<int> answer;
    for (auto &entry : topNodes)
    {
        answer.push_back(entry.second.second);
    }
    return answer;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(5);
    vector<int> answer = topView(root);
    for (int value : answer)
    {
        cout << value << " ";
    }
    return 0;
}