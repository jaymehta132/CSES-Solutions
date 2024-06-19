#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#define ll long long int
#define fio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pb push_back

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

struct employee{
    ll id;
    vector <employee*> subordinate;
    employee* boss = nullptr; 
    ll count = 0;
    bool visited = false;
};

ll count_subordinate(employee* boss){
    if (boss->visited){
        return boss->count;
    }
    boss->visited=true;
    if (boss->subordinate.empty()){
        return 0;
    }
    for (ll i=0; i<boss->subordinate.size(); i++){
        boss->count += count_subordinate((boss->subordinate)[i]) + 1;
    }
    return boss->count;
}

int main() {
    fio();
    ll n;
    cin>>n;
    employee office[n];
    for (ll i=1; i<n; i++){
        ll in;
        cin>>in;
        office[i].boss = &office[in-1];
        office[in-1].subordinate.pb(&office[i]);
    }
    for (ll i=0; i<n; i++){
        cout<<count_subordinate(&office[i])<<" ";
    }

}