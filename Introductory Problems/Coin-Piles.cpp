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
    vector <string> output;
    for (ll k=0; k<t; k++){
        ll a,b;
        cin>>a>>b;
        if ((2*a-b)%3 == 0 && (2*b-a)%3 == 0 && 2*a >= b && 2*b >= a){
            output.push_back("YES\n");
        }
        else{
            output.push_back("NO\n");
        }
    }
    for (ll k=0; k<t; k++){
        cout<<output[k];
    }
}