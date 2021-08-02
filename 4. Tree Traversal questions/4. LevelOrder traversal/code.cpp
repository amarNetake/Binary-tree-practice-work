vector<int> levelOrder(Node* root)
{
  //Your code here
    if(root==NULL)
    {
        return {};
    }
    queue<Node*> q;
    q.push(root);
    vector<int> vect;
    while(q.empty()==false)
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
        vect.push_back(temp->data);
    }
    return vect;
}