/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{

public:
    pair<int, int> dfs(TreeNode *Node, int &cnt)
    {
        if (Node == NULL)
        {
            return {
                0,
                0,
            };
        }
        auto lh = dfs(Node->left, cnt);
        auto rh = dfs(Node->right, cnt);
        int sum = Node->val + lh.first + rh.first;
        int ele = 1 + lh.second + rh.second;
        if (sum / ele == Node->val)
        {
            cnt++;
        }
        return {sum, ele};
    }
    int averageOfSubtree(TreeNode *root)
    {
        int cnt = 0;
        dfs(root, cnt);
        return cnt;
    }
};