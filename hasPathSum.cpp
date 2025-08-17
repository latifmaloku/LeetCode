/*Given the root of a binary tree and an integer targetSum,
return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.
*/

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
    // returns true if node has no children
    bool isLeaf(TreeNode* node)
    {
        if((nullptr == node->left) && (nullptr == node->right))
        {
            return true;
        }
        return false;
    }

    bool hasSum(TreeNode* node, int sum, int targetSum)
    {
        // we have reached end without solution.
        // return false
        if(node == nullptr)
        {
            return false;
        }
        sum += node->val;

        // if this a leaf node, see if targetSum has been found
        if(isLeaf(node)){
            if (sum == targetSum)
            {
                return true;
            }
            return false;
        }
        // search left child
        if(hasSum(node->left, sum, targetSum))
        {
            return true;
        }
        // search right child
        if(hasSum(node->right, sum, targetSum))
        {
            return true;
        }
        // no targetSum found
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return hasSum(root,0,targetSum);
    }
};