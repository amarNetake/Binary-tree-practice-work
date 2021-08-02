vector<int> verticalOrder(Node *root)
{
    //Your code here
    map<int,vector<int>> ma;
    queue<pair<Node*,int>> q;
    q.push(make_pair(root,0));
    int countNodes;
    while(1)
    {
        countNodes=q.size();
        if(countNodes==0)
        {
            break;
        }
        while(countNodes>0)
        {
            pair<Node*,int> p=q.front();
            q.pop();
            Node* curr=p.first;
            int x=p.second;
            ma[x].push_back(curr->data);
            if(curr->left!=NULL)
            {
                q.push(make_pair(curr->left,x-1));
            }
            if(curr->right!=NULL)
            {
                q.push(make_pair(curr->right,x+1));
            }
            countNodes--;
        }
    }
    vector<int> result;
    for(auto x:ma)
    {
        for(int y:x.second)
        {
            result.push_back(y);
        }
    }
    return result;
}