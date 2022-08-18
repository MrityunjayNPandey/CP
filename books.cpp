#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n, t, sum=0, k=0, p, i ,j , sum2=0, u=0, q=0;
    cin>>n>>t;
    int a[n], p[n];
    for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
    for(i=0;i<n;i++)
        {
            sum+=a[i];      
        }
    if(sum<=t)
        {cout<<n;k++}
    if(k==0)
    {
        for(i=0;i<n;i++)
            {
                        for(j=i;j<n;j++)
                            {
                                sum2+=a[j]
                                if(sum2>=t)
                                    {
                                        p[u]=n-i-j-1;
                                    }
                            }                
            }
    }
    if(k==0)
        {   
            int q=sizeof(p) / sizeof(q[0]);
            sort(p, p + q);
            cout<<p[q];
        }
}
int main()
{
    solve();
}




