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
    vector<vector<ll>> prefTrees(n+1, vector<ll>(n+1, 0));
    for (ll i=1; i<=n; i++){
        for (ll j=1; j<=n; j++){
            char a;
            cin>>a;
            if (a == '*'){
                prefTrees[i][j] += 1;
            }
            prefTrees[i][j] += (prefTrees[i][j-1] + prefTrees[i-1][j] - prefTrees[i-1][j-1]);
        }
    }
    queue <ll> outp;
    for (ll k=0; k<q; k++){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        ll ans = prefTrees[c][d] - prefTrees[a-1][d] - prefTrees[c][b-1] + prefTrees[a-1][b-1];
        outp.push(ans);
    }
    for (ll i=0; i<q; i++){
        cout<<outp.front()<<"\n";
        outp.pop();
    }
}