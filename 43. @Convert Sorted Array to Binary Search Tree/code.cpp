class Solution {
public:
    
    TreeNode* createBST(vector<int>& nums,int s,int e)
    {
        if(s>e) return NULL;
        int m=s+(e-s)/2;
        TreeNode* new_node=new TreeNode(nums[m]);
        new_node->left=createBST(nums,s,m-1);
        new_node->right=createBST(nums,m+1,e);
        return new_node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        if(n==0)  return NULL;
        TreeNode* root=createBST(nums,0,nums.size()-1);
        return root;
    }
};