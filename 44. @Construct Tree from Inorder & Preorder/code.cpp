class Solution {
public:
    TreeNode* constructBT(unordered_map<int,int>& ma,vector<int>& inorder,vector<int>& preorder,int s,int e,int& curr)
    {
        if(s>e) 
        {
            curr--;
            return NULL;
        }
        if(s==e)
        {
            TreeNode* new_node=new TreeNode(inorder[s]);
            return new_node;
        }
        TreeNode* root=new TreeNode(preorder[curr]);
        int m=ma[preorder[curr]];
        root->left=constructBT(ma,inorder,preorder,s,m-1,++curr);
        root->right=constructBT(ma,inorder,preorder,m+1,e,++curr);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> ma;
        for(int i=0;i<inorder.size();i++)
        {
            ma[inorder[i]]=i;
        }
        int curr=0;
        TreeNode* root=constructBT(ma,inorder,preorder,0,preorder.size()-1,curr);
        return root;
    }
};