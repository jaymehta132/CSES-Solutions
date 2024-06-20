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
 
struct movie{
    ll arr;
    ll dep;
};
 
bool compare(movie &a, movie &b){
    //if (a.dep == b.dep){
    //    return a.arr < b.arr;
    //}
    //else{
        return a.dep < b.dep;
    //}
}
 
int main() {
    ll n,k;
    cin>>n>>k;
    movie movies[n];
    for (ll i=0; i<n; i++){
        cin>>movies[i].arr>>movies[i].dep;
    }
    sort(movies, movies + n, compare);
    multiset <ll> member;
    ll count=0;

    for(ll i = 0; i<k; i++){
        member.insert(-1);
    }


    for (ll i=0; i<n; i++){
        auto it = member.upper_bound(movies[i].arr);
        if (it != member.begin()){
            --it;
            member.erase(it);
            member.insert(movies[i].dep);
            count+=1;
        }
    }
    cout<<count;
}