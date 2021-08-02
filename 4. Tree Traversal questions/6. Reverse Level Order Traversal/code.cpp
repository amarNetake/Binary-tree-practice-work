vector<int> reverseLevelOrder(Node *root)
{
    // code here
    if(root==NULL)
    {
        return {};
    }
    vector<int> vect;
    stack<Node*> t;  //This stack will hold the ith level data from right to left
    stack<Node*> s;  //Once entire level is traversed then the data is shifted from stack 't' to stack 's'. Stack s will hold the final result
    queue<Node*> q;  //For the level order traversal operation.
    int nodeCount;
    q.push(root);
    while(1)
    {
        nodeCount=q.size();
        if(nodeCount==0)
        {
            break;
        }
        while(nodeCount>0)
        {
            Node* temp=q.front();
            t.push(temp);
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
        while(t.empty()==false)
        {
            s.push(t.top());
            t.pop();
        }
    }
    while(s.empty()==false)
    {
        vect.push_back(s.top()->data);
        s.pop();
    }
    return vect;
}