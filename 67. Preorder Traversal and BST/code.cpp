#include <bits/stdc++.h>
using namespace std;

void checkBST(vector<int>& vect,int n,int l,int r,int& i)
{
    if(l>r || i==n || vect[i]<l || vect[i]>r) // vect[i] must be in range of [l,r] to be valid BST
    {
        return;
    }
    int val= vect[i++];
    checkBST(vect,n,l,val-1,i);
    checkBST(vect,n,val+1,r,i);
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
	    int i=0;
	    checkBST(vect,n,INT_MIN,INT_MAX,i);
	    cout<<(i==n)<<"\n";
	}
	return 0;
}