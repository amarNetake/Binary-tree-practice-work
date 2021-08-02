vector<int> inOrder(Node* root)
{
    // Your code here
    stack<Node*> s;
    vector<int> vect;
    Node* temp=root;
    while(temp!=NULL||s.empty()==false)
    {
        while(temp!=NULL)
        {
            s.push(temp);
            temp=temp->left;
        }
        temp=s.top();
        s.pop();
        vect.push_back(temp->data);
        temp=temp->right;
    }
    return vect;
}