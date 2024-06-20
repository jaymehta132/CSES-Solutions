#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

typedef long long ll;
typedef tree<pair<ll,int>,null_type,less<pair<ll,int>>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

struct cmp{
    bool operator() (const pair<ll,ll>& a, const pair<ll,ll>& b) const{
        if(a.first < b.first)
            return true;
        else if(a.first == b.first){
            return a.second > b.second;
        }
        return false;
    }
};

int main(){
    int n;
    cin >> n;

    vector<pair<ll,ll>> ranges;
    map<pair<ll,ll>, int> index_map;
    for(int i = 0; i<n; i++){
        ll x,y;
        cin >> x >> y;
        index_map[make_pair(x,y)] = i;
        ranges.push_back(make_pair(x,y));
    }

    vector<int> contains_result(n);
    vector<int> contained_result(n);

    sort(ranges.begin(), ranges.end(), cmp());

    indexed_set end_points;

    // for contained
    for(int i = 0; i<n; i++){
        end_points.insert(make_pair(ranges[i].second,-i));
        int order = end_points.order_of_key(make_pair(ranges[i].second,-i));
        contained_result[index_map[ranges[i]]] = i - order;
    }

    end_points.clear();

    // for contains
    for(int i  = n-1; i>=0; i--){
        end_points.insert(make_pair(ranges[i].second,-i));
        int order = end_points.order_of_key(make_pair(ranges[i].second,-i));
        contains_result[index_map[ranges[i]]] = order;
    }

    for(auto i :contains_result){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i :contained_result){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}