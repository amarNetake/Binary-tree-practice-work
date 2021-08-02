class Solution {
    int skewsum; 
    int sum;
public:
    Solution maxpathUtil(TreeNode* root,TreeNode* ROOT)
    {
        if(root->left==NULL&&root->right==NULL)
        {
            Solution s;
            s.sum=root->val;
            s.skewsum=root->val;
            return s;
        }
        Solution lh,rh;
        bool visLh=false,visRh=false;
        if(root->left!=NULL)
        {
            lh=maxpathUtil(root->left,ROOT);
            visLh=true;
        }
        if(root->right!=NULL)
        {
            rh=maxpathUtil(root->right,ROOT);
            visRh=true;
        }
        if(visLh==true&&visRh==true)
        {
            Solution s;
            vector<int> vect;
            vect.push_back(lh.sum);
            vect.push_back(rh.sum);
            vect.push_back(lh.skewsum+root->val);
            vect.push_back(rh.skewsum+root->val);
            vect.push_back(root->val);
            vect.push_back(lh.skewsum+rh.skewsum+root->val);
            s.sum=*max_element(vect.begin(),vect.end());
            s.skewsum=*max_element(vect.begin()+2,vect.begin()+5); //Upperbound exclusive
            return s;
        }
        if(visLh==true&&visRh==false)
        {
            Solution s;
            vector<int> vect;
            vect.push_back(lh.sum);
            vect.push_back(lh.skewsum+root->val);
            vect.push_back(root->val);
            s.sum=*max_element(vect.begin(),vect.end());
            s.skewsum=*max_element(vect.begin()+1,vect.end()); //Upperbound exclusive
            return s;
        }
        if(visLh==false&&visRh==true)
        {
            Solution s;
            vector<int> vect;
            vect.push_back(rh.sum);
            vect.push_back(rh.skewsum+root->val);
            vect.push_back(root->val);
            s.sum=*max_element(vect.begin(),vect.end());
            s.skewsum=*max_element(vect.begin()+1,vect.end()); //Upperbound exclusive
            return s;
        }
        Solution s;
        s.sum=0;
        s.skewsum=0;
        return s;
    }
    int maxPathSum(TreeNode* root) {
        Solution s=maxpathUtil(root,root);
        return s.sum;
    }
};