#include<bits/stdc++.h>
using namespace std;

class SGTree{
    public:
      
      vector<int> seg;
    
    SGTree(int n)
    {
        seg.resize(4*n+1);
    }
      
     
    void build(int idx,int low,int high,int arr[])
    {
        if (low==high)
        {
            seg[idx]=arr[low];
            return;
        }
        
        int mid=(low+high)/2;
        build(2*idx+1,low,mid,arr);
        build(2*idx+2,mid+1,high,arr);
        
        seg[idx]=min(seg[2*idx+1],seg[2*idx+2]);
    }


    int query(int idx,int low,int high,int l,int r)
    {
        if (low>r || high<l)
        return INT_MAX;
        else if (low>=l && high<=r)
        return seg[idx];
        
        int mid=(low+high)/2;
        
        return min(query(2*idx+1,low,mid,l,r),query(2*idx+2,mid+1,high,l,r));
        
    }

    void update(int idx ,int low,int high,int i,int val)
    {
        if (low==high)
        {
            seg[idx]=val;
            return;
        }
        
        int mid=(low+high)/2;
        if (i<=mid)
        {
            update(2*idx+1,low,mid,i,val);
        }
        else
        {
            update(2*idx+2,mid+1,high,i,val);
        }
        
        seg[idx]=min(seg[2*idx+1],seg[2*idx+2]);  
        
    } 
     
};






int main()
{
    int n;
    cin>>n;
    
    int arr[n];
    
    for (int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        arr[i]=x;
    }
    
    int seg[4*n];
    
    build(0,0,n-1,arr,seg);
    int q;
    cin>>q;
    
    while (q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<query(0,0,n-1,l,r,seg)<<endl;
    }
 
 return 0;   
}
