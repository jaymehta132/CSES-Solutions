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
    int colour;
    set <city*> neighbours;
};

int main() {
    ll n,m;
    cin>>n>>m;
    city arr[n];
    bool pushed[n], visited[n];
    for (ll i=0; i<n; i++){
        arr[i].id = i;
        arr[i].colour = 0;
        pushed[i] = false;
        visited[i] = false;
    }
    for (ll j=0; j<m; j++){
        ll a,b;
        cin>>a>>b;
        arr[a-1].neighbours.insert(&arr[b-1]);
        arr[b-1].neighbours.insert(&arr[a-1]);
    }
    int col = 1;
    vector <int> indices;
    for (ll i=0; i<n; i++){
        if (!pushed[i]){
            stack <city*> order;
            indices.push_back(i+1);
            order.push(&arr[i]);
            pushed[i] = true;
            while (!order.empty()){
                (*order.top()).colour = col;
                city current = *order.top();
                order.pop();
                for (auto it = current.neighbours.begin(); it != current.neighbours.end(); it++){
                    if (!pushed[(**it).id]){
                        order.push(*it);
                        pushed[(**it).id] = true;
                    }
                }
            }
            col++;
        }
    }
    cout<<col-2<<"\n";
    for (int j=1; j<indices.size();j++){
        cout<<indices[0]<<" "<<indices[j]<<"\n";
    }
}