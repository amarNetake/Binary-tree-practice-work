void printSpiral(Node *root)
{
    //Your code here
    if(root==NULL)
    {
        return;
    }
    stack <Node*> s1;	//To store the level of tree in "right to left" order of popping
    stack <Node*> s2;	//To store the level of tree in "left to right" order of popping
    s1.push(root);
    while(s1.empty()==false || s2.empty()==false)
    {
        while(s1.empty()==false)
        {
            Node* temp=s1.top();
            s1.pop();
            cout<<temp->data<<" ";
            if(temp->right!=NULL)
            {
                s2.push(temp->right);
            }
            if(temp->left!=NULL)
            {
                s2.push(temp->left);
            }
        }
        while(s2.empty()==false)
        {
            Node* temp=s2.top();
            s2.pop();
            cout<<temp->data<<" ";
            if(temp->left!=NULL)
            {
                s1.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                s1.push(temp->right);
            }
        }
    }
}