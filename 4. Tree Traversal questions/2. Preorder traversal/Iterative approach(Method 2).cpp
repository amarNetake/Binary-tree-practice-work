vector <int> preorder(Node* root)
{
  // Your code here
    if(root==NULL)
    {
        return {};
    }
    vector<int> vect;
    stack<pair<Node*,int>> s;
    s.push(make_pair(root,1));
    while(s.empty()==false)
    {
        pair<Node*,int> curr=s.top();
        Node* topNode= curr.first;
        int state=curr.second;
        if(state==1)
        {
            vect.push_back(topNode->data);   
            if(topNode->left!=NULL)
            {
                s.top().second++;
                s.push(make_pair(topNode->left,1));
            }
            else
            {
                s.top().second++;
            }
        }
        else if(state==2)
        {
            if(topNode->right!=NULL)
            {
                s.top().second++;
                s.push(make_pair(topNode->right,1));
            }
            else
            {
                s.top().second++;
            }
        }
        else
        {
            s.pop();
        }
    }
    return vect;
}