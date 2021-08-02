#include <bits/stdc++.h>
using namespace std;

void postorder(vector<int>& vect,int n,int l,int r,int& i,int& k)
{
    if(l>r || i==n || vect[i] < l || vect[i]>r)
    {
        return;
    }
    int val=vect[i++];
    postorder(vect,n,l,val-1,i,k);
    postorder(vect,n,val+1,r,i,k);
    vect[k++]=val;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int> vect(n);
	    for(int i=0;i<n;i++)
	    {
	        cin>>vect[i];
	    }
	    int ind=0;
	    int ind1=0;
	    postorder(vect,n,INT_MIN,INT_MAX,ind,ind1);
	    for(int x: vect)
	    {
	        cout<<x<<" ";
	    }
	    cout<<"\n";
	}
	return 0;
}