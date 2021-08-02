vector<int> topView(struct Node *root)
{
    if(root==NULL)  return {};
    vector<int> result;
    unordered_map<int,bool> ma;
    map<int,Node*> temp;
    queue<pair<Node*,int>> q;
    q.push(make_pair(root,0));
    int countNodes;
    while(1)
    {
        countNodes=q.size();
        if(countNodes==0)  break;
        while(countNodes>0)
        {
            pair<Node*,int> curr=q.front();
            q.pop();
            if(ma.find(curr.second)==ma.end())
            {
                temp[curr.second]=curr.first;
                ma[curr.second]=true;
            }
            if(curr.first->left!=NULL) q.push(make_pair(curr.first->left,curr.second-1));
            if(curr.first->right!=NULL)  q.push(make_pair(curr.first->right,curr.second+1));
            countNodes--;
        }
    }
    for(auto x: temp)
    {
        result.push_back(x.second->data);
    }
    return result;
}