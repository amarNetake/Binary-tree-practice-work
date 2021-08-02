void levelOrder(Node* root)
{
  //Your code here
    if(root==NULL)
    {
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(1)
    {
        int nodeCount=q.size();
        if(nodeCount==0)  //Queue became empty.
        {
            break;
        }
        while(nodeCount>0)
        {
            Node* temp=q.front();
            cout<<temp->data<<" ";
            q.pop();
            if(temp->left!=NULL)
            {
                q.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                q.push(temp->right);
            }
            nodeCount--;
        }
        cout<<"$ "; //When nodeCount becomes 0 then we reach here =>all nodes in ith level are traversed
    }
}