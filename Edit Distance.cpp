#include<bits/stdc++.h>
using namespace std;
 
#define   fi(a,b) for(int i=a;i<b;i++)
#define   fj(a,b) for(int j=a;j<b;j++)
#define   ff first
#define   ss second
#define   ll long long
#define   ld long double
#define   ull unsigned long long
#define   bp(x) __builtin_popcount(x)
#define   pr(x) for(auto it: x) cout<<it<<" "; cout<<endl;
#define   getMax(x) max_element(x.begin(),x.end())
#define   getMin(x) min_element(x.begin(),x.end())
#define   endl "\n"
typedef   vector<int> vi;
typedef   vector< pair<int,int> > vii;
typedef   vector<long long> vl;
typedef   pair<int,int> pii;
typedef   pair<ll,ll> pll;
typedef   vector< pair<ll,ll> > vll;
//int dx[]={1,0,-1,0};
//int dy[]={0,1,0,-1};
//int dx[]={-1,0,1,1,1,0,-1,-1};
//int dy[]={-1,-1,-1,0,1,1,1,0};
 
void nikal_pehli_fursat_mai(){
    string a,b;
    cin>>a>>b;
    int n=a.size(),m=b.size();
    
    ll dp[n+1][m+1];
    iota(dp[0],dp[0]+m+1,0);
    for(int i=1;i<=n;i++) dp[i][0]=i;
 
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        if( a[i-1] == b[j-1] ){
            dp[i][j] = dp[i-1][j-1];
        }
        else{
            dp[i][j] = min({ dp[i][j-1], dp[i-1][j], dp[i-1][j-1] }) + 1;
        }
      }
    }
    cout<<dp[n][m]<<endl;
    // fi(0,n+1){
    //     fj(0,m+1){
    //         cout<<dp[i][j]<<" ";
    //     }cout<<endl;
    // }
}
 
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc=1; 
    // cin>>tc;
    while(tc--){
    nikal_pehli_fursat_mai();
    }
}