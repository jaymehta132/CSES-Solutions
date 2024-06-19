#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#define ll long long int

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int main() {
    ll n;
    cin>>n;
    vector <ll> coins;
    ll sum=0;
    for (ll i=0; i<n; i++){
        ll in;
        cin>>in;
        coins.push_back(in);
        sum += in;
    }

    vector <vector<bool>> dp(n+1, vector<bool>(sum+1, false));
    dp[0][0] = true;

    for (ll i=1; i<n+1; i++){
        for (ll j=0; j<sum+1; j++){
            dp[i][j] = dp[i-1][j];
            if (j>=coins[i-1] && dp[i-1][j-coins[i-1]]){
                dp[i][j] = true;
            }
        }
    }
    vector <ll> sums;

    for (ll j=1; j<sum+1; j++){
        if (dp[n][j]){
            sums.push_back(j);
        }
    }
    cout<<sums.size()<<"\n";
    for (ll i=0; i<sums.size(); i++){
        cout<<sums[i]<<" ";
    }
}