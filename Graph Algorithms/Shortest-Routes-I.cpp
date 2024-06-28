#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#define ll long long int
#define fio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pb push_back
#define mp make_pair
#define MAX 200001
#define pll pair<ll,ll>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

struct city{
    ll id;
    ll cost;
    bool visited = false;
    set<pair<ll,city*>> neighbours;
    city* prev = nullptr;
};

struct CustomCompare {
    bool operator()(const pll& lhs, const pll& rhs) {
        // Custom comparison logic here (for example, min-heap)
        return lhs.first > rhs.first;
    }
};

city* region[MAX];

int main() {
    fio();
    ll n,m;
    cin>>n>>m;
    for (ll i=1; i<=n; i++){
        city* gm1 = new city;
        gm1->id = i;
        region[i] = gm1;
    }
    ll sum_cost = 0;
    for (ll i=0; i<m; i++){
        ll a,b,c;
        cin>>a>>b>>c;
        sum_cost += c;
        region[a]->neighbours.insert(mp(c, region[b]));
    }
    for (ll i=1; i<=n; i++){
        region[i]->cost = sum_cost;
    }

    region[1]->cost = 0;
    priority_queue <pll, vector<pll>, CustomCompare> pq;
    pq.push(mp(0, 1));
    while(!pq.empty()){
        pll current = pq.top();
        pq.pop();
        city* current_city = region[current.second];
        if (!current_city->visited){
            ll curr_cost = current.first;
            current_city->visited = true;
            for (auto& element : current_city->neighbours){
                city* next = element.second;
                ll potCost = element.first;
                if (next->cost > current_city->cost + potCost){
                    next->cost = current_city->cost + potCost;
                    pq.push(mp(next->cost, next->id));
                }
            }
        }
    }
    for (ll i=1; i<=n; i++){
        cout<<region[i]->cost<<" ";
    }
}