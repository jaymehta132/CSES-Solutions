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

unsigned ll collatz(unsigned ll x){
    if (x%2==0){
        x = x/2;
    }
    else{
        x = 3*x + 1;
    }
    return x;
}

int main() {
    unsigned ll n,x;
    cin>>n;
    x = n;
    vector <ll> ans;
    ans.push_back(x);
    while(x>1){
        x = collatz(x);
        ans.push_back(x);
    }
    for (int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}