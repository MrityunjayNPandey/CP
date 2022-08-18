#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,k=0;
    cin>>n;
    int a[n][2], b[n][2];
    for(i=0;i<n;i++)
        for(j=0;j<2;j++)
            {cin>>a[i][j];}
    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++)
            {
                if(a[j][0]<a[j+1][0])
                {
                    k=a[j][0];
                    a[j][0]=a[j+1][0];
                    a[j+1][0]=k;
                }
            }
    for(i=0;i<n;i++)
       { for(j=0;j<2;j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
       }
    k=0;
    //for(i=0;i<n-1;i++)
        // for(j=0;j<n;j++)
        //     {
        //         if(a[j][0]==a[j+1][0])
        //             {   cout<<j<<endl;
        //                 if(a[j][1]<a[j+1][1])
        //                     {
        //                         k=a[j][0];
        //                         a[j][0]=a[j+1][0];
        //                         a[j+1][0]=k;
        //                     }
        //             }
        //     }(
    
    for(i=0;i<n;i++)
       { for(j=0;j<2;j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
       }
    k=0;int l=0;
    while((n-k)==0)
        {
            if(k<a[n-k][1])
                {
                    k+=a[n-k][0];
                    k++;
                }
            else
                {
                    l+=a[n-k][0];
                }
        }
    
    cout<<((k-1)*2)+(l-1); 
}