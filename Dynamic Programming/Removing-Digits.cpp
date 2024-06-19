#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#define ll long long int

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int main() {
    ll n;
    cin>>n;
    ll x = n;
    ll steps = 0;
    while (x>0){
        set <int> digits;
        ll temp = x;
        while (temp>0){
            ll temp1 = temp%10;
            digits.insert(temp1);
            temp = temp/10;
        }
        x = x - *digits.rbegin();
        steps+=1;
    }
    cout<<steps;
}