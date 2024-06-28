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
#define MAX 200001

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int main() {
    ll n,q;
    cin>>n>>q;
    ll prefixXOR[n+1];
    prefixXOR[0] = 0;
    for (ll i=1; i<=n; i++){
        ll a;
        cin>>a;
        prefixXOR[i] = prefixXOR[i-1] ^ a;
    }
    queue <ll> outp;
    for (ll i=0; i<q; i++){
        ll a,b;
        cin>>a>>b;
        ll ans = prefixXOR[b] ^ prefixXOR[a-1];
        outp.push(ans);
    }
    for (ll i=0; i<q; i++){
        cout<<outp.front()<<"\n";
        outp.pop();
    }
}