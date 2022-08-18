#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n=0,m=0,i=0,j=0,u=0;
            cin>>n>>m;                                          //n=checkpoints, m=players or no. of path
            //cout<<n<<m<<endl;
            int a[n][m],b[(m*n)-m],c[n][m],h[n][m],f[m];
                for(i=0;i<n;i++)
                    {
                        for(j=0;j<m;j++)
                            {
                                cin>>a[i][j];
                            }
                    }
                for(i=1;i<n;i++)
                    {
                        for(j=0;j<m;j++)
                            {
                                b[u]=a[i][j];                       //making 1-(n-1) rows to 1D array(b)
                                ++u;
                            }
                    }
                                                            
                
                int p=sizeof(b) / sizeof(b[0]);
                sort(b, b + p);                                     //sorting that(b) 1d array
                
                // //
                

                // for(i=0;i<u;i++)
                //     {
                //         cout<<b[i];
                //     }
                // cout<<endl;
                

                for(i=0;i<n;i++)
                    {
                        for(j=0;j<m;j++)
                            {
                                c[i][j]=a[i][j]; 
                                h[i][j]=a[i][j];                    //temporary array(2D)(c)
                            }
                    }
                
 
                // for(i=0;i<n;i++)
                //     {
                //         for(j=0;j<m;j++)
                //             {
                //                 cout<<a[i][j]<<endl;                     //temporary array(2D)(c)
                //             }
                //     }
 
 
                
                u=0;
                int d[1000],e[1000];
                j=0,i=1;
                while(i<n)
                    {
                        if(u==m)
                            {break;}
                        while(j<m)
                            {
                                if(u==m)
                                    break;
                                if(b[u]==a[i][j])
                                    {
                                        //cout<<a[i][j]<<"running"<<endl;
                                        d[u]=i;
                                        e[u]=j;        //storing the i,j values of the smallest nos with the 
                                        ++u;           //help of 1D array(only m nos)(b) and storing it in array d(i),e(j)
                                        a[i][j]=0;
                                        i=1;
                                        j=0;
                                        //cout<<a[i][j]<<"running"<<u<<endl;
                                    }
                                else
                                    j++;
                                //cout<<"running"<<endl;
                            }
                        j=0;
                        i++;
                    }
 
                // for(i=0;i<n;i++)
                //     {
                //         for(j=0;j<m;j++)
                //             {
                //                 cout<<a[i][j]<<endl;                     //temporary array(2D)(c)
                //             }
                //     }
                // for(i=0;i<u;i++)
                //     {
                //         cout<<d[i]<<endl<<e[i]<<endl;
                //     }
                
 
                for(j=0;j<m;j++)
                    {
                        f[j]=a[0][j];                   //making another 1D array(f) for 1st row
                    }  
                int q=sizeof(f) / sizeof(f[0]), g[10000];
                sort(f, f + q);                         //sorting this array(f)
 
 
 
                // for(i=0;i<u;i++)
                //     {
                //         cout<<f[i]<<endl;
                //     }
 
 
 
 
                u=0,j=0; 
                while(j<m)
                    {
                        if(u==m)
                            break;
                        if(f[u]==a[0][j])
                            {
                                    g[u]=j;
                                    a[0][j]=0;      //storing the j values of the smallest nos with the 
                                    ++u;            //help of new 1D array(f)(of m numbers) and storing in array g
                                    j=0;
                            }
                        else
                            j++;
                    }
 
 
                // for(i=0;i<u;i++)
                //     {
                //         cout<<g[i]<<endl;
                //     }
 
 
                // for(i=0;i<n;i++)
                //     {
                //         for(j=0;j<m;j++)
                //             {
                //                 cout<<a[i][j];                     //temporary array(2D)(c)
                //             }
                //     }
                // cout<<endl;
 
 
 
                u=0;
                int r=0;   
                
 
                for(j=0;j<m;j++)
                    {
                        if(h[d[u]][e[u]]==c[d[u]][e[u]])
                        {
                            //cout<<endl<<c[d[u]][g[m-u-1]]<<endl;
                            r=c[d[u]][g[m-u-1]];
                            //cout<<c[d[u]][e[u]];
                            c[d[u]][g[m-u-1]]=c[d[u]][e[u]];
                            c[d[u]][e[u]]=r;
                        }
                        ++u;
                    }
 
 
                for(i=0;i<n;i++)
                    {
                        for(j=0;j<m;j++)
                            {
                                cout<<c[i][j]<<" ";              //printing the modified array
                            }
                        cout<<endl;
                    }       
}
int main()
{
    int t = 1;
    cin>>t;     
    while(t--) 
        {   
            solve();                
        }
}
