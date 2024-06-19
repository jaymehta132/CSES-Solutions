#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#define ll long long int

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int main() {
    ll n,x;
    cin>>n>>x;
    vector <ll> prices, pages;
    for (ll i=0; i<n; i++){
        ll in;
        cin>>in;
        prices.push_back(in);
    }
    for (ll i=0; i<n; i++){
        ll in;
        cin>>in;
        pages.push_back(in);
    }
    
    vector <ll> dp(x+1, 0);
    for (ll i=0; i<n; i++){
        for (ll c=x; c>0; c--){
            if (prices[i] <= c){
                dp[c] = max (dp[c], pages[i] + dp[c-prices[i]]);
            }
        }
    }
    cout<<dp[x];
}