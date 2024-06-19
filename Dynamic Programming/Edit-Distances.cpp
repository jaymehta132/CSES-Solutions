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
    string str1;
    string str2;
    cin>>str1;
    cin>>str2;
    ll n = str1.length();
    ll m = str2.length();
    ll dp[n+1][m+1];
    for (ll i=0; i<n+1; i++){
        for (ll j=0; j<m+1; j++){
            if (i==0){
                dp[i][j] = j;
            }
            else if (j==0){
                dp[i][j] = i;
            }
            else if (str1[i-1]==str2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = 1+ min (dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
            }
        }
    }
    cout<<dp[n][m];
}