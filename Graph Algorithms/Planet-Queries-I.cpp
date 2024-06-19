#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#define ll long long int
#define fio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int main() {
    fio();
    ll n,q;
    cin>>n>>q;
    vector <vector<ll>> dp(n+1, vector<ll>(30));
    for (ll i=1; i<=n; i++){
        ll in;
        cin>>in;
        dp[i][0] = in;
    }
    vector <pair<ll,ll>> queries;
    vector <ll> answers;
    for (ll i=0; i<q; i++){
        ll a,b;
        cin>>a>>b;
        queries.push_back(make_pair(a,b));
    }

    for (ll i=1; i<30; i++){
        for (ll j=1; j<=n; j++){
            dp[j][i] = dp[dp[j][i-1]][i-1];
        }
    }

    for (ll k=0; k<q; k++){
        ll start = queries[k].first;
        ll steps = queries[k].second;
        ll ans = start;
        for (ll j = 0; j < 30; j++) {
            if (steps & (1 << j)) { // check if the j-th bit is set
                ans = dp[ans][j];
            }
        }
        answers.push_back(ans);
    }
    for (ll i=0; i<q; i++){
        cout<<answers[i]<<"\n";
    }
}