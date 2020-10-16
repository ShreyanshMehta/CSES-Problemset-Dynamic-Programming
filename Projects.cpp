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
    cin >> n;
    map<int,int> compress;
    vector<int> a(n),b(n),p(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> p[i];
        b[i]++;
        compress[a[i]], compress[b[i]];
    }
 
    int coords = 0;
    for (auto&v : compress) {
        v.second = coords++;
    }
 
    vector<vector<pair<int,int>>> project(coords);
    for (int i = 0; i < n; i++) {
        project[ compress[b[i]] ].emplace_back( compress[a[i]], p[i] );
    }
 
    vector<long long> dp(coords, 0);
    for (int i = 0; i < coords; i++) {
        if (i > 0) {
          dp[i] = dp[i-1];
        }
        for (auto p : project[i]) {
          dp[i] = max(dp[i], dp[p.first]+p.second);
        }
    }
    cout << dp[coords-1] << endl;
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