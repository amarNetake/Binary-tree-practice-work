vector<int> ExtremeNodes(Node* root)
{
    // Your code here
    if(root==NULL)
    {
        return {};
    }
    bool right=true;
    vector<int> vect;
    queue<Node*> q;
    q.push(root);
    int countNodes;
    while(1)
    {
        countNodes=q.size();
        if(countNodes==0)
        {
            break;
        }
        if(right==false)
        {
            vect.push_back(q.front()->data);
        }
        while(countNodes>0)
        {
            Node* temp=q.front();
            q.pop();
            if(right==true&&countNodes==1)
            {
                vect.push_back(temp->data);
            }
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
        right= !right;
    }
    return vect;
}