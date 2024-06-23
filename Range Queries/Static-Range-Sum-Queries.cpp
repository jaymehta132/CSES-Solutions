#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#define fio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pb push_back
#define mp make_pair
#define MAX 200001
#define ll long long int

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int main() {
    fio();
    ll n,q;
    cin>>n>>q;
    vector<ll> values(n);
    vector<ll> prefixSums(n+1);
    for (ll i=0; i<n; i++){
        cin>>values[i];
    }
    prefixSums[0] = 0;
    for (ll i=1; i<n+1; i++){
        prefixSums[i] = prefixSums[i-1] + values[i-1];
    }

    for (ll i=0; i<q; i++){
        ll a,b;
        cin>>a>>b;
        cout<<prefixSums[b]-prefixSums[a-1]<<"\n";
    }
}