int findBottomLeftValue(TreeNode* root) 
{
    queue<TreeNode*> q;
    q.push(root);
    int countNodes=0;
    int first;
    while(1)
    {
        countNodes= q.size();
        if(countNodes==0)
        {
            break;
        }
        first=q.front()->val;
        while(countNodes>0)
        {
            TreeNode* temp=q.front();
            q.pop();
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
    }
    return first;
}