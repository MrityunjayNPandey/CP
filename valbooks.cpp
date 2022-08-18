#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n,t,i=0,j=0,m=0;
    cin>>n>>t;
    int a[n],b[n];
    for(i=0;i<n;i++)
        {cin>>a[i];}
    for(i=0;i<n;i++)
    {   j=i;
        m=0;
        while(m<=t&&j<n)
            {   
                m+=a[j];
                j++;
                b[i]+=1;
                //cout<<b[i];
            }  
        if(m>t) 
        b[i]-=1;
        // cout<<endl;
        //  cout<<b[i]<<endl;
    }
    int q=sizeof(b) / sizeof(b[0]);
    sort(b, b + q);
    // for(i=0;i<q;i++)
    // cout<<b[i];
    cout<<b[p-1];
}
int main()
{
    solve();
}




