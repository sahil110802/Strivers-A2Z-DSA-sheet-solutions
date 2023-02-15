class Solution {
public:
    vector<int>s;
    void func(TreeNode* node, int level,vector<int>&s){
        
        if(!node)return;
        if(level==s.size())s.push_back(node->val);
        func(node->right,level+1,s);
        func(node->left,level+1,s);
    }
    vector<int> rightSideView(TreeNode* root) {
        func(root,0,s);
        return s;
        
    }
};
