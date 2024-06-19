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
    string input;
    cin>>input;
    ll ans=1;
    ll count=1;
    for (ll i=1; i<input.length(); i++){
        if (input[i]==input[i-1]){
            count++;
            ans = max(ans, count);
        }
        else{
            count=1;
        }
    }
    cout<<ans;
}