class status{
    public:
        int largest;
        int smallest;
        int minDiff;
};
class Solution {
public:
    
    status findMinDiff(TreeNode* root)
    {
        if(root==NULL)
        {
            status s;
            s.largest=-1e7;
            s.smallest=1e7;
            s.minDiff=1e7;
            return s;
        }
        status lh=findMinDiff(root->left);
        status rh=findMinDiff(root->right);
        
        status s;
        s.largest=max({lh.largest,rh.largest,root->val});
        s.smallest=min({lh.smallest,rh.smallest,root->val});
        s.minDiff=min({root->val-lh.largest,rh.smallest-root->val,lh.minDiff,rh.minDiff});
        return s;
        
    }
    
    int minDiffInBST(TreeNode* root) {
        if(root==NULL)  return 0;
        status s=findMinDiff(root);
        return s.minDiff;
    }
};