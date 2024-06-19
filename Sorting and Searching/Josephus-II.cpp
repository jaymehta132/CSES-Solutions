#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#define ll long long int

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int main() {
    ll n,k;
    cin>>n>>k;
    ordered_set children;
    for (ll i=0; i<n; i++){
        children.insert(i+1);
    }
    ll idx = 0;
    while(!children.empty()){
        ll size = children.size();
        idx = (idx + k)%size;
        auto it = children.find_by_order(idx);
        cout<<*it<<" ";
        children.erase(it);
    }
}