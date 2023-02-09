class Solution {
public:
    bool leaf(Node* root){
        if(root->left==NULL and root->right==NULL)return true;
        return false;
    }
    void addLeft(Node* root, vector<int> &res){
        Node* cur=root->left;
        while(cur){
            if(!leaf(cur))res.push_back(cur->data);
            if(cur->left)cur=cur->left;
            else cur=cur->right;
        }
    }
    void addRight(Node* root, vector<int> &res){
        Node* cur=root->right;
        vector<int>tmp;
        while(cur){
            if(!leaf(cur))tmp.push_back(cur->data);
            if(cur->right)cur=cur->right;
            else cur=cur->left;
        }
        for(int i=tmp.size()-1;i>=0;i--){
            res.push_back(tmp[i]);
        }
    }
    void addLeaf(Node* root, vector<int> &res){
        if(leaf(root)){
            res.push_back(root->data);
            return;
        }
        if(root->left)addLeaf(root->left,res);
        if(root->right)addLeaf(root->right,res);
    }
    
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int>res;
        if(!root)return res;
        if(!leaf(root))res.push_back(root->data);
        addLeft(root,res);
        addLeaf(root,res);
        addRight(root,res);
        return res;
    }
};
