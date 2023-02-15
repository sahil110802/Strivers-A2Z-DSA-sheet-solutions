class Solution {
public:
    bool isIde(TreeNode* r1, TreeNode*r2){
        if(!r1 and !r2)return true;
        if(!r1 or !r2)return false;
        if(r1->val!=r2->val)return false;
        return isIde(r1->left,r2->right) and isIde(r1->right,r2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return isIde(root,root);
    }
};
