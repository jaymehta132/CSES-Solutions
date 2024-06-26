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

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

struct city{
    ll id;
    city* prev = nullptr;
    set <city*> neighbours;
    ll level = 1;
    bool visited = false;
};

city* dfs(city* start){
    stack <city*> order;
    order.push(start);
    while (!order.empty()){
        city* current = order.top();
        order.pop();
        current->visited = true;
        for (auto& elem: current->neighbours){
            if (!elem->visited){
                order.push(elem);
                elem->prev = current;
            }
            if (elem->visited && elem != current->prev){
                elem->prev = current;
                return elem;
            }
        }
    }
    return nullptr;
}

int main() {
    ll n,m;
    cin>>n>>m;
    city* region[MAX];
    for (ll i=i; i<n+1; i++){
        city* gm1 = new city;
        gm1->id = i;
        region[i] = gm1;
    }

    for (ll i=0; i<m; i++){
        ll a,b;
        cin>>a>>b;
        region[a]->neighbours.insert(region[b]);
        region[b]->neighbours.insert(region[a]);
    }

    city* final_city;
    for (ll i=1; i<n+1; i++){
        if(!region[i]->visited){
            final_city = dfs(region[i]);
            if (final_city != nullptr){
                break;
            }
        }
    }

    if (final_city == nullptr) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    stack <city*> cycle;
    cycle.push(final_city);
    city* cycle_city = final_city->prev;
    while (cycle_city != final_city){
        cycle.push(cycle_city);
        cycle_city = cycle_city->prev;
    }
    cycle.push(final_city);
    cout<<cycle.size()<<"\n";
    while(!cycle.empty()){
        city* current = cycle.top();
        cout<<current->id<<" ";
        cycle.pop();
    }
}