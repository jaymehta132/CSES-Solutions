#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#define ll long long int

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

struct city{
    int id;
    vector <city*> neighbours;
    city* prev = nullptr;
};

int main() {
    ll n,m;
    cin>>n>>m;
    city arr[n];
    bool pushed[n], visited[n];
    for (ll i=0; i<n; i++){
        arr[i].id = i;
        pushed[i] = false;
        visited[i] = false;
    }
    for (ll j=0; j<m; j++){
        ll a,b;
        cin>>a>>b;
        arr[a-1].neighbours.push_back(&arr[b-1]);
        arr[b-1].neighbours.push_back(&arr[a-1]);
    }

    queue <city*> order;
    order.push(&arr[0]);
    pushed[0] = true;
    bool reached = false;
    while (!order.empty() && !reached){
        city* current = order.front();
        order.pop();
        for (auto it = current->neighbours.begin(); it != current->neighbours.end(); it++){
            if (!pushed[(*it)->id]){
                order.push(*it);
                (*it)->prev = current;
                pushed[(*it)->id] = true;
                if (*it == &arr[n-1]){
                    reached = true;
                    break;
                }
            }
        }
    }
    if (!reached){
        cout<<"IMPOSSIBLE";
    }
    else{
        stack <city*> path;
        path.push(&arr[n-1]);
        city* current = path.top();
        while((current)->prev!=nullptr){
            current = (current)->prev;
            path.push(current);
        }
        cout<<path.size()<<"\n";
        while(!path.empty()){
            cout<<(path.top())->id+1<<" ";
            path.pop();
        }
    }
}