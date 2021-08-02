int getMaxWidth(Node* root)
{
    // Your code here
    if(root==NULL)
    {
        return 0;
    }
    queue<Node*> q;
    q.push(root);
    int countNodes;
    int max=1;
    while(1)
    {
        countNodes=q.size();
        if(countNodes==0)
        {
            break;
        }
        while(countNodes>0)
        {
            Node* temp=q.front();
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
        if(max< q.size())
        {
            max=q.size();
        }
    }
    return max;
}