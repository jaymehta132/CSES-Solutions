#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#define ll long long int

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int main() {
    ll t;
    cin>>t;
    vector <ll> outp;
    for (ll k=0; k<t; k++){
        ll x,y;
        cin>>y>>x;
        ll ans;
        if (y>=x){
            if (y%2==1){
                ll tmp = (y-1)*(y-1);
                ans = tmp + x;
            }
            else{
                ll tmp = (y)*(y);
                ans = tmp + 1 - x;
            }
        }
        else{
            if (x%2==1){
                ll tmp = (x)*(x);
                ans = tmp + 1 - y;
            }
            else{
                ll tmp = (x-1)*(x-1);
                ans = tmp + y;
            }
        }
        outp.push_back(ans);
    }
    for (ll k=0; k<t; k++){
        cout<<outp[k]<<"\n";
    }
}