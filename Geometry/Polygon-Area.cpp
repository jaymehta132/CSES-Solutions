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
    vector <ll> x,y;
    for (ll i=0; i<n; i++){
        ll a,b;
        cin>>a>>b;
        x.push_back(a);
        y.push_back(b);
    }
    ll sum1=0;
    ll sum2=0;
    for (ll i=0; i<n; i++){
        if (i<n-1){
            sum1+= (x[i]*y[i+1]);
        }
        else{
            sum1+= (x[n-1]*y[0]);
        }
        if (i>0){
            sum2+= (x[i]*y[i-1]);
        }
        else{
            sum2+= (x[0]*y[n-1]);
        }
    }
    ll ans = abs(sum1-sum2);
    cout<<ans;
}