#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>
#define ll long long int

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int main() {
    ll n;
    cin>>n;
    vector <vector <char>> grid(n, vector<char>(n));
    for (ll i=0; i<n; i++){
        for (ll j=0; j<n; j++){
            char in;
            cin>>in;
            grid[i][j] = in;
        }
    }
    vector <vector <ll>> ways(n , vector<ll>(n, 0));
    ll mod = 1e9+7;
    for (ll i=0; i<n; i++){
        for (ll j=0; j<n; j++){
            if (i!=0 && j!=0){
                ways[i][j] += (ways[i-1][j] + ways[i][j-1])%mod;
            }
            else if(i==0 && j!=0){
                ways[i][j] = ways[i][j-1];
            }
            else if(j==0 && i!=0){
                ways[i][j] = ways[i-1][j];
            }
            else{
                ways[i][j] = 1;
            }
            if (grid[i][j] == '*'){
                ways[i][j] = 0;
            }
        }
    }
    cout<<ways[n-1][n-1];
}