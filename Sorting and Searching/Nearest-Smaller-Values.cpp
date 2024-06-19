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
    ll n;
    cin>>n;
    vector <ll> values;
    for (ll i=0; i<n; i++){
        ll in;
        cin>>in;
        values.push_back(in);
    }
    stack <ll> idx;
    for (ll i=0; i<n; i++){
        while (!idx.empty() && values[idx.top()]>=values[i]){
            idx.pop();
        }
        if (idx.empty()){
            cout<<"0"<<" ";
        }
        else{
            cout<<idx.top()+1<<" ";
        }
        idx.push(i);
    }
}