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
    int n;
    cin>>n;
    ll sum = 0;
    vl v(n); 
    fi(0,n) {
        cin>>v[i];
        sum += v[i];
    }
    pll dp[n][n];
    memset(dp, 0, sizeof(dp));
    fi(0,n) dp[i][i] = {v[i], 0};
 
    fj(1,n){
        fi(0,n-j){
            if(v[i] + dp[i+1][i+j].ss > dp[i][i+j-1].ss + v[i+j]){
                dp[i][i+j].ff = v[i] + dp[i+1][i+j].ss;
                dp[i][i+j].ss = dp[i+1][i+j].ff;
            }
            else{
                dp[i][i+j].ff = v[i+j] + dp[i][i+j-1].ss;
                dp[i][i+j].ss = dp[i][i+j-1].ff;
            }
        }
    }
 
    // fi(0,n){
    //     fj(0,n){
    //         cout<<"{"<<dp[i][j].ff<<","<<dp[i][j].ss<<"}"<<" ";
    //     }cout<<endl;
    // }
 
    cout<< dp[0][n-1].ff <<endl;
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