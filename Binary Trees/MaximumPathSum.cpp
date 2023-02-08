class Solution {
public:
void help(TreeNode* root, int &result){

    if(!root)return 0;
    int l=help(root->left,result);
    int r=help(root->right,result);
    int a=max(max(l,r)+root->val,root->val);
    int b=max(a,l+r+root->val);
    result=max(result,b);
    return a;
}
    int maxPathSum(TreeNode* root) {
        int result=INT_MIN;
        help(root,result);
        return result;
    }
};
