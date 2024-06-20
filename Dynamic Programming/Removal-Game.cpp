#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#define ll long long int
#define fio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pb push_back
#define mp make_pair

using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int main() {
    fio();
    ll n;
    cin>>n;
    vector<ll> value(n);
    for (ll i=0; i<n; i++){
        cin>>value[i];
    }

    vector<vector<ll>> dp1(n, vector<ll>(n,0));
    vector<vector<ll>> dp2(n, vector<ll>(n,0));
    //dp1[a][b] gives max value for p1 when array is from index a to index b

    vector <ll> prefixSums(n+1, 0);
    for (ll i=0; i<n; i++){
        dp1[i][i] = value[i];
        dp2[i][i] = value[i];
    }
    for (ll i=1; i<=n; i++){
        prefixSums[i] = prefixSums[i-1] + value[i-1];
    }

    for (ll i=1; i<n; i++){
        ll row = 0;
        ll j = row+i;
        while (j<n){
            dp1[row][j] = max(value[row] + (prefixSums[j+1] - prefixSums[row+1] - dp2[row+1][j]) , value[j] + (prefixSums[j] - prefixSums[row] - dp2[row][j-1]));
            dp2[row][j] = max(value[row] + (prefixSums[j+1] - prefixSums[row+1] - dp1[row+1][j]) , value[j] + (prefixSums[j] - prefixSums[row] - dp1[row][j-1]));
            row = (row + 1)%n;
            j = i+row;
        }
    }

    cout<<dp1[0][n-1];
}