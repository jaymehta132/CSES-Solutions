#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
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
    ll n,q;
    cin>>n>>q;
    ll dp[n+1][21];
    dp[0][0] = 0;
    dp[1][0] = 0;
    for (ll i = 2; i<n+1; i++){
        ll a;
        cin>>a;
        dp[i][0] = a;
    }

    for (ll j=1; j<21; j++){
        for (ll i=0; i<n+1; i++){
            dp[i][j] = dp[dp[i][j-1]][j-1];
        }
    }

    for (ll i=0; i<q; i++){
        ll a,b;
        cin>>a>>b;
        ll x=a;
        for (ll j=0; j<21; j++){
            if (b&(1<<j)){
                x = dp[x][j];
            }
        }
        if (x==0){
            cout<<"-1"<<"\n";
        }
        else{
            cout<<x<<"\n";
        }
    }
}