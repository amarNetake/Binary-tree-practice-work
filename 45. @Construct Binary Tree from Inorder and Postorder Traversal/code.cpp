class Solution {
public:
    TreeNode* constructBT(unordered_map<int,int>& ma,vector<int>& inorder,vector<int>& postorder,int s,int e,int& curr)
    {
        if(s>e)
        {
            curr++;
            return NULL;
        }
        if(s==e)        
        {
            TreeNode* new_node=new TreeNode(inorder[s]);
            return new_node;
        }
        TreeNode* root=new TreeNode(postorder[curr]);
        int m=ma[postorder[curr]];
        root->right=constructBT(ma,inorder,postorder,m+1,e,--curr);
        root->left=constructBT(ma,inorder,postorder,s,m-1,--curr);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> ma;
        int n=inorder.size();
        for(int i=0;i<inorder.size();i++)
        {
            ma[inorder[i]]=i;
        }
        int curr=n-1;
        TreeNode* root=constructBT(ma,inorder,postorder,0,n-1,curr);
        return root;
    }
};
