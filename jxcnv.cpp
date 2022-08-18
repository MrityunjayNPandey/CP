#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 

void solve(){
    int xk, yk, x1, y1, x2, y2;
    cin>>xk>>yk;
    cin>>x1>>y1>>x2>>y2;
    if(xk!=1 && xk!=8 && yk!=1 && yk!=8)
        cout<<"NO";
    else if((abs(xk-x1)==1 && abs(yk-y1)==1) || (abs(xk-x2)==1 && abs(yk-y2)==1))
        cout<<"NO";
    else{
        bool b=0;
        if(yk==1)
        {
            if(xk!=1 && xk!=8)
            {
                if(y1==2)
                {
                    if(x1!=x2 && x2!=xk+1 && x2!=xk-1)
                        b=1;
                }
                else if(y2==2)
                {
                    if(x1!=x2 && x1!=xk+1 && x1!=xk-1)
                        b=1;
                }
            }
            else if(xk==1 || xk==8)
            {
                if(y1==2)
                {
                    if(x1!=x2 && x2!=xk+1 && x2!=xk-1)
                        b=1;
                }
                else if(y2==2)
                {
                    if(x1!=x2 && x1!=xk+1 && x1!=xk-1)
                        b=1;
                }
                else if(x1==2 && xk==1)
                {
                    if(y1!=y2 && y2!=2)
                        b=1;
                }
                else if(x2==2 && xk==1)
                {
                    if(y1!=y2 && y1!=2)
                        b=1;
                }
                else if(x1==7 && xk==8)
                {
                    if(y1!=y2 && y2!=2)
                        b=1;
                }
                else if(x2==7 && xk==8)
                {
                    if(y1!=y2 && y1!=2)
                        b=1;
                }
            }    
        }
        else if(yk==8)
        {
            if(xk!=1 && xk!=8)
            {
                if(y1==7)
                {
                    if(x1!=x2 && x2!=xk+1 && x2!=xk-1)
                        b=1;
                }
                else if(y2==7)
                {
                    if(x1!=x2 && x1!=xk+1 && x1!=xk-1)
                        b=1;
                }
            }
            else if(xk==1 || xk==8)
            {
                if(y1==7)
                {
                    if(x1!=x2 && x2!=xk+1 && x2!=xk-1)
                        b=1;
                }
                else if(y2==7)
                {
                    if(x1!=x2 && x1!=xk+1 && x1!=xk-1)
                        b=1;
                }
                else if(x1==2 && xk==1)
                {
                    if(y1!=y2 && y2!=7)
                        b=1;
                }
                else if(x2==2 && xk==1)
                {
                    if(y1!=y2 && y1!=7)
                        b=1;
                }
                else if(x1==7 && xk==8)
                {
                    if(y1!=y2 && y2!=7)
                        b=1;
                }
                else if(x2==7 && xk==8)
                {
                    if(y1!=y2 && y1!=7)
                        b=1;
                }
            }    
        }
        else if(xk==1)
        {
            if(yk!=1 && yk!=8)
            {
                if(x2==2)
                {
                    if(y1!=y2 && y1!=yk+1 && y1!=yk-1)
                        b=1;
                }
                else if(x1==2)
                {
                    if(y1!=y2 && y2!=yk+1 && y2!=yk-1)
                        b=1;
                }
            }
        }
        else if(xk==8)
        {
            if(yk!=1 && yk!=8)
            {
                if(x2==7)
                {
                    if(y1!=y2 && y1!=yk+1 && y1!=yk-1)
                        b=1;
                }
                else if(x1==7)
                {
                    if(y1!=y2 && y2!=yk+1 && y2!=yk-1)
                        b=1;
                }
            }
        }
        if(b==1)
            cout<<"YES";
        else
            cout<<"NO";
    }
    cout<<endl;
}

int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        solve();
    }
    return 0;
}