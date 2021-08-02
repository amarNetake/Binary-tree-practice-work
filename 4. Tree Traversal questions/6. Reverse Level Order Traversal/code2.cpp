vector<vector<int>> levelOrderBottom(TreeNode* root) 
{
    if(root==NULL)
    {
        return {};
    }
    vector<int> vect;
    vector<vector<int>> result;
    queue<TreeNode*> q;
    q.push(root);
    int countNodes=0;
    while(1)
    {
        countNodes=q.size();
        if(countNodes==0)
        {
            break;
        }
        while(countNodes>0)
        {
            TreeNode* temp=q.front();
            q.pop();
            vect.push_back(temp->val);
            if(temp->left!=NULL)
            {
                q.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                q.push(temp->right);
            }
            countNodes--;
        }
        result.push_back(vect);
        vect={};
    }
    reverse(result.begin(),result.end());
    return result;
}