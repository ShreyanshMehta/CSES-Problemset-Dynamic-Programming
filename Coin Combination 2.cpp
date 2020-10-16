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
 
const int mod=1e9+7;
 
void nikal_pehli_fursat_mai(){
  int n, x;
  cin >> n >> x;
  vector<int> v(n+1);
  fi(1,n+1)
      cin >> v[i];
  int dp[n+1][x+1];

  for(int i = 1; i <= n; i++){
      for(int sum = 0; sum <= x; sum++){
          if(sum == 0)
              dp[i][sum] = 1;
          else{
              int op1 = (v[i] > sum) ? 0 : dp[i][sum - v[i]];
              int op2 = (i == 1) ? 0 : dp[i-1][sum];
              dp[i][sum] = (op1 + op2) % mod;
          }
      }
  }

  cout << dp[n][x];
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