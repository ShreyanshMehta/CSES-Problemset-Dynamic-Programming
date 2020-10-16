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
 
const int MOD=1e9+7;
long long power(long long x, long long y) { 
    long long res = 1;
    x = x % MOD;
    while (y > 0) { 
        if (y & 1) 
            res = (res*x) % MOD; 
        y = y>>1;
        x = (x*x) % MOD; 
    } 
    return res; 
}
 
long long modInv(ll x){
  return power(x, MOD-2);
}
 
long long modAdd(long long a, long long b){
  return (a%MOD + b%MOD + 2*MOD)%MOD;
}
 
long long modMult(long long a,long long b){
  return (a%MOD*b%MOD)%MOD;
}
 
long long modDiv(long long a,long long b){
  return (a%MOD*modInv(b)%MOD)%MOD;
}
 
void nikal_pehli_fursat_mai(){
    int n,m;
    cin>>n>>m;
    vl v(n); fi(0,n) cin>>v[i];
    ll dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    fi(1,m+1){
      dp[0][i]=1;
    }
    ll ans=1;
    fi(0,n){
      if(v[i]){
        ans = modMult( ans, dp[i][v[i]]);
        fj(1, m+1) dp[i][j] = 0;
        dp[i][v[i]]=1;
      }
      for(int k=1;k<=m;k++){
          fj(-1,2){
              if(k+j<=m && k+j>=1) {
                dp[i+1][k+j] = modAdd(dp[i+1][k+j], dp[i][k]);
              }
          }
      }
    }
    if(!v[n-1]){
        ll sum=0;
        fj(1,m+1){
            sum = modAdd(sum, dp[n-1][j]); 
        }
        ans = modMult(ans, sum);
    }
    cout<<ans<<endl;
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