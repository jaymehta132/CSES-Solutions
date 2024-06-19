#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int main() {
    int n,x;
    cin>>n>>x;
    vector <int> coins;
    for (int i=0; i<n; i++){
        int in;
        cin>>in;
        coins.push_back(in);
    }
    int mod = 1e9 + 7;
    vector <vector<int>> dp(n+1, vector <int>(x+1, 0));
    dp[0][0]=1;
    for (int i=1; i<n+1; i++){
        for (int j=0; j<x+1; j++){
            dp[i][j] = dp[i-1][j];
            if (j>=coins[i-1]){
                dp[i][j] = (dp[i][j] + dp[i][j - coins[i-1]])%mod;
            }
        }
    }
    cout<<dp[n][x];
}