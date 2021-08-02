class status{
    public:
        long int smallest;
        long int largest;
        bool isBST;
};

class Solution {
public:
    status UtilIsBST(TreeNode* root)
    {
        if(root==NULL)
        {
            status s;
            s.smallest=LONG_MAX;   // Since inputs are in long int so taking LONG_MAX 
            s.largest=LONG_MIN;
            s.isBST=true;
            return s;
        }
        status lh=UtilIsBST(root->left);
        if(lh.isBST==false)  return lh;
        status rh=UtilIsBST(root->right);
        if(rh.isBST==false)  return rh;
        
        status s;
        s.smallest=min({lh.smallest,rh.smallest,(long int)root->val});
        s.largest=max({lh.largest,rh.largest,(long int)root->val});
        if(lh.largest>=root->val || rh.smallest<=root->val)  s.isBST=false;
        else s.isBST=true;
        return s;
    }
    
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        
        status s=UtilIsBST(root);
        return s.isBST;
    }
};