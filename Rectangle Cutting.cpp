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
    ll a,b;
    cin>>a>>b;
    if(a>b) swap(a,b);
    ll dp[b+3][b+3];
    fi(0,b+1){
        fj(0,b+1){
            if(i==0 || j==0 || i==j) dp[i][j] = 0;
            else dp[i][j] = 1e18;
        }
    }
    fi(1,a+1){
        fj(i+1,b+1){
            for(int k=1;k<=i;k++){
                dp[i][j] = min({dp[i][j], dp[i-k][j]+dp[k][j-k]+1+(k!=i), dp[i-k][k]+dp[i][j-k]+1+(k!=i)});
            }
            dp[j][i] = dp[i][j];
        }
    }
    // fi(0,a+1){
    //     fj(0,b+1){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dp[a][b]<<endl;
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