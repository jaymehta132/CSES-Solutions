#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#define ll long long int

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

ll solve(ll a, ll b){
    vector <vector<ll>> cuts(a+1, vector<ll>(b+1, 1e9));
    for (ll i=0; i<a+1; i++){
        for (ll j=0; j<b+1; j++){
            if (i==j){
                cuts[i][j]=0;
            }
            else{
                for (ll k=0; k<j; k++){
                    cuts[i][j] = min(cuts[i][j], cuts[i][j-k] + cuts[i][k] + 1);
                }
                for (ll k=0; k<i; k++){
                    cuts[i][j] = min(cuts[i][j], cuts[i-k][j] + cuts[k][j] + 1);
                }
            }
        }
    }
    return cuts[a][b];
}

int main() {
    ll a,b;
    cin>>a>>b;
    ll ans = solve(a,b);
    cout<<ans;
}