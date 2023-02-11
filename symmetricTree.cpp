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

    bool isSymmetricHelp(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL && t2 == NULL) {
            return true;
        } else if ((t1 == NULL && t2 != NULL) || (t1 != NULL && t2 == NULL)) {
            return false;
        } else if (t1->val == t2->val) {
            bool leftSymmetry = isSymmetricHelp(t1->left, t2->right);
            bool rightSymmetry = isSymmetricHelp(t1->right, t2->left);

            if (leftSymmetry == true && rightSymmetry == true) {
                return true;
            } else {
                return false;
            }
        
        } else {
            return false;
        }
    }

    bool isSymmetric(TreeNode* root) {
        
        // recursive solution
        bool isSymmetricBool = isSymmetricHelp(root->left, root->right);
        return isSymmetricBool;

    }
};
