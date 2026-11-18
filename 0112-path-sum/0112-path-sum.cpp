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
    bool recurse(TreeNode* node,int sum,int targetSum){
        
        if(node->left == NULL && node->right == NULL){
            if(sum == targetSum){
                return true;
            }
            return false;
        }
       bool ans = false;
       if(node->left != NULL){
       ans = ans || recurse(node->left,sum+(node->left->val),targetSum);
       }
       if(node->right != NULL){
       ans = ans || recurse(node->right,sum+(node->right->val),targetSum);
       }
       return ans;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return false;
        }
        return recurse(root,root->val,targetSum);
    }
};