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
    vector <bool> Exists(n, false);
    for (ll i=0; i<n-1; i++){
        ll in;
        cin>>in;
        Exists[in-1] = true;
    }
    ll i=0;
    while(Exists[i]){
        i++;
    }
    cout<<i+1;
}