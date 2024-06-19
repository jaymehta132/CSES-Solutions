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

struct pupil{
    ll id;
    set <pupil*> friends;
    int team = 0;
};

int main() {
    ll n,m;
    cin>>n>>m;
    pupil arr[n];
    bool pushed[n], visited[n];
    for (ll i=0; i<n; i++){
        arr[i].id = i;
        pushed[i] = false;
        visited[i] = false;
    }
    for (ll j=0; j<m; j++){
        ll a,b;
        cin>>a>>b;
        arr[a-1].friends.insert(&arr[b-1]);
        arr[b-1].friends.insert(&arr[a-1]);
    }

    int team1 = 1;
    int team2 = 2;
    bool impossible = false;
    for (ll i=0; i<n; i++){
        if (!pushed[i] && !impossible){
            stack <pupil*> order;
            order.push(&arr[i]);
            pushed[i] = true;
            arr[i].team = team1;
            while (!order.empty()){
                pupil current = *order.top();
                int current_team = current.team;
                order.pop();
                for (auto it = current.friends.begin(); it != current.friends.end(); it++){
                    if ((**it).team == current_team){
                        impossible = true;
                        break;
                    }
                    else if (!pushed[(**it).id]){
                        order.push(*it);
                        (**it).team = !(current_team-1) + 1;
                        pushed[(**it).id] = true;
                    }
                }
            }
        }
    }
    if (impossible){
        cout<<"IMPOSSIBLE";
    }
    else{
        for (ll i=0; i<n; i++){
            cout<<arr[i].team<<" ";
        }
    }
}