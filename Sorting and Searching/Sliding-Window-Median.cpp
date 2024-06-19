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
    ll n,k;
    cin>>n>>k;
    vector <ll> values;
    for (ll i=0; i<n; i++){
        ll in;
        cin>>in;
        values.push_back(in);
    }
    multiset <ll> lwr, upr;
    for (ll i=0; i<n; i++){
        if (i>=k){
            if (lwr.find(values[i-k]) != lwr.end()){
                lwr.erase(lwr.find(values[i-k]));
            }
            else{
                upr.erase(upr.find(values[i-k]));
            }
        }
        if (lwr.size() <= upr.size()){
            lwr.insert(values[i]);
        }
        else{
            upr.insert(values[i]);
        }
        if (lwr.size()>0 && upr.size()){
            ll lwrmax = *lwr.rbegin();
            ll uprmin = *upr.begin();
            if (lwrmax > uprmin){
                lwr.insert(uprmin);
                upr.insert(lwrmax);
                lwr.erase(lwr.find(lwrmax));
                upr.erase(upr.find(uprmin));
            }
        }
        if (i>=k-1){
            ll median = *lwr.rbegin();
            cout<<median<<" ";
        }
    }
}