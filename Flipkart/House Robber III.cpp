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
    int tryrob(int &l, int &r, TreeNode *root)
    {
        if (!root)
            return 0;
        int lr = 0, ll = 0, rl = 0, rr = 0;
        l = tryrob(ll, lr, root->left);
        r = tryrob(rl, rr, root->right);

        return max(root->val + ll + lr + rr + rl, l + r);
    }

    int rob(TreeNode *root)
    {
        int l, r;
        return tryrob(l, r, root);
    }
};