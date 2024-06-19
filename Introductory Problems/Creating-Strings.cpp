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
    set <string> ans;
    sort(input.begin(), input.end());
    ans.insert(input);
    while (next_permutation(input.begin(), input.end())){
        ans.insert(input);
    }  
    cout<<ans.size()<<"\n";
    for (auto it=ans.begin(); it!=ans.end(); it++){
        cout<<*it<<"\n";
    }
}