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
    vector <ll> coins;
    for (ll i=0; i<n; i++){
        ll in;
        cin>>in;
        coins.push_back(in);
    }
    sort(coins.begin(), coins.end());
    ll x = 1;
    for (ll i=0; i<n; i++){
        if (coins[i] > x){
            break;
        }
        else{
            x+=coins[i];
        }
    }
    cout<<x;
}