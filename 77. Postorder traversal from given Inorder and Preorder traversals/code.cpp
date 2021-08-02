void createPostorder(vector<int> in,vector<int> pre,vector<int>& post,int s,int e,int& itr,int& loc)
{
    if(s>e || itr>in.size())
    {
        return;
    }
    vector<int>::iterator pos=find(in.begin(),in.end(),pre[loc++]);
    int mid= distance(in.begin(),pos);
    createPostorder(in,pre,post,s,mid-1,itr,loc);
    createPostorder(in,pre,post,mid+1,e,itr,loc);
    post[itr++]=in[mid];
}

void printPostOrder(int in[], int pre[], int n)
{
//Your code here
    if(n==0)
    {
        return;
    }
    vector<int> ino(in,in+n);
    vector<int> preo(pre,pre+n);
    vector<int> post(n);
    int itr=0;
    int loc=0;
    createPostorder(ino,preo,post,0,n-1,itr,loc);
    for(int x:post)
    {
        cout<<x<<" ";
    }
}