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
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool isSame;
        // if we have reached the end of a tree then they are the same
        if (p == nullptr && q == nullptr)
        {
            return true;
        }
        // if one is empty and the other is not, then they are not the same
        if(p == nullptr || q == nullptr)
        {
            return false;
        }
        // if values are not the same, then the trees are different
        if(p->val != q->val)
        {
            return false;
        }
        //explore left children
        isSame = isSameTree(p->left,q->left);
        // if left is not the same, then return false. No need to explore right
        if(isSame == false)
        {
            return false;
        }
        // explore right children
        isSame = isSameTree(p->right,q->right);
        return isSame;
    }
};