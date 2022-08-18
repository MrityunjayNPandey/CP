#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define PI 3.1415926535897932384626
const int mod = 1'000'000'007;
const int N = 3e5, M = N;
 
 
void solve() {
int i, j, n, m;
   string s;
   cin>>s;
   n=s.length();
   string str;
   fo(i,n){
int count=0;
       int x=str.length();
        if(i==0){
           str=str+s[i];
       }
       else{
           for(j=0;j<x;j++){
               if(str[j]==s[i]){
                  count++; 
               }
           }
           if(count==0){
                   str=str+s[i];
               }
       }
   }
   
   m=str.length();
 
   if(m%2==0){
       cout<<"CHAT WITH HER!"<<endl;
   }
   else{
       cout<<"IGNORE HIM!"<<endl;
   }
    
}
 
int main() {
ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
srand(chrono::high_resolution_clock::now().time_since_epoch().count());
 
 
int t = 1;
// cin >> t;
 
while(t--) {
solve();
}
 
return 0;
}