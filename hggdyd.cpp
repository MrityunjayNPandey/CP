#include<bits/stdc++.h>
using namespace std;
void solve()
    {
        int n,m=0;
        cin>>n;
        int a[n],i,j;
        for(i=0;i<n;i++)
            {
                cin>>a[i];
                for(i=0;i<n;i++)
                        for(j=i;j<n;j++)
                            {
                                if(a[i]*a[j]==i+j+2)
                                    m++;
                            }
                cout<<m;
            }
    }
int main()
{
    int t=0;
    cin>>t;
    while(t--)
        {
            solve();
        }
}