int findmaxPathSum(TreeNode* root,int& answer)
    {
        if(root==NULL)
        {
            return 0;
        }
        int lh=findmaxPathSum(root->left,answer);
        int rh=findmaxPathSum(root->right,answer);
        
        answer=max(answer,root->val+lh+rh);
        
        /*
            skew entity returned with either 
            1. 0 (return 0 if sum is not maximizing if sum is <0 better to count neither of the nodes in the final result)
            2. Just current node
            3. Current node with left result
            4. current node with right result
        */
        return max(0,root->val+max(lh,rh));
    }
    int maxPathSum(TreeNode* root) {
        
        int answer=INT_MIN;
        findmaxPathSum(root,answer);  //We can ignore the returned value also if we do not need it in final result
        return answer;
    }