vector <int> preorder(Node* root)
{
  // Your code here
    if(root==NULL)
    {
        return {};
    }
    vector<int> vect;
    stack<Node*> s;
    Node* temp=root;
    while(temp!=NULL||s.empty()==false)
    {
        while(temp!=NULL)
        {
            vect.push_back(temp->data);
            s.push(temp);
            temp=temp->left;
        }
        temp=s.top();
        s.pop();
        temp=temp->right;
    }
    return vect;
}