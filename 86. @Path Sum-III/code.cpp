class Solution {
public:
    void pathSumUtil(TreeNode* root,int& targetSum,int sum,unordered_map<int,int>& ma,int& count)
    {
        if(root==NULL)  return;
        sum=sum+root->val;
        if(ma.find(sum-targetSum)!=ma.end()) count=count+ma[sum-targetSum];
        ma[sum]++;
        pathSumUtil(root->left,targetSum,sum,ma,count);
        pathSumUtil(root->right,targetSum,sum,ma,count);
        ma[sum]--;   //Backtrack
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)  return 0;
        unordered_map<int,int> ma;
        ma[0]=1;
        int count=0;
        
        pathSumUtil(root,targetSum,0,ma,count);
        return count;
    }
};