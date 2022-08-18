#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int i,j,n=0,m=0,p=0,q=0,r=0,s=0; 
    char a[3][3];
    for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
                cin>>a[i][j];
        }
    if(a[0][0]==a[0][1]==a[0][2])
        {
            p++;
        }
    if(a[1][0]==a[1][1]==a[1][2])
        {
            p++;
        }
    if(a[2][0]==a[2][1]==a[2][2])
        {
            p++;
        }
    if(a[0][0]==a[1][1]==a[2][2])
        {
            p++;
        }
    if(a[0][2]==a[1][1]==a[2][0])
        {
            p++;
        }
    if (p!=0)
        {cout<<3;}
    else if(p==0)
    {
            hello:
            n=0,m=0,s=0;
            for(i=0;i<3;i++)
                {
                    for(j=0;j<3;j++)
                        {
                            if(a[i][j]=='_')
                                {
                                    
                                    a[i][j]='X';
                                    n=i;
                                    m=j;
                                    j=2;
                                    i=2;
                                    s++;
                                }
                        }
                }
            if(a[0][0]==a[0][1]==a[0][2])
                {
                    cout<<1;
                }
            else if(a[1][0]==a[1][1]==a[1][2])
                {
                    cout<<1;
                }
            else if(a[2][0]==a[2][1]==a[2][2])
                {
                    cout<<1;
                }
            else if(a[0][0]==a[1][1]==a[2][2])
                {
                    cout<<1;
                }
            else if(a[0][2]==a[1][1]==a[2][0])
                {
                    cout<<1;
                }
            else if(s!=0)
                {
                    a[n][m]='O';
                    if(a[0][0]==a[0][1]==a[0][2])
                        {
                            cout<<1;
                        }
                    else if(a[1][0]==a[1][1]==a[1][2])
                        {
                            cout<<1;
                        }
                    else if(a[2][0]==a[2][1]==a[2][2])
                        {
                            cout<<1;
                        }
                    else if(a[0][0]==a[1][1]==a[2][2])
                        {
                            cout<<1;
                        }
                    else if(a[0][2]==a[1][1]==a[2][0])
                        {
                            cout<<1;
                        }
                    else   
                        {
                            a[n][m]='0+r';
                            r++;
                            goto hello;
                        }
                }
    }
else
cout<<2;    
}
int main()
{
    int t;
    cin>>t;
    for (i=0;i<n;i++)
        {
            solve();
        }
}