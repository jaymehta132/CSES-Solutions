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
    ll n;
    cin>>n;
    vector <ll> values;
    for (ll i=0; i<n; i++){
        ll in;
        cin>>in;
        values.push_back(in);
    }
    vector <ll> dp;
    for (ll i=0; i<n; i++){
        ll x = values[i];
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if (it==dp.end()){
            dp.push_back(x);
        }
        else{
            *it = x;
        }
    }
    cout<<dp.size();
}