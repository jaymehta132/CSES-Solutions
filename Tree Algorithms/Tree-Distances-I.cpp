#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#define ll long long int
#define fio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pb push_back
#define mp make_pair

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

struct node{
    ll id;
    ll level = 0;
    ll level_final = 0;
    bool pushed = false;
    vector <node*> neighbours;
};

node* dfs_level(node* root){
    stack <node*> order;
    order.push(root);
    root->level = 0;
    root->pushed = true;
    node* largest = root;
    while (!order.empty()){
        node* current = order.top();
        order.pop();
        ll curr_lvl = current->level;
        for (ll i=0; i<current->neighbours.size(); i++){
            node* temp = current->neighbours[i];
            if (!temp->pushed){
                temp->level = curr_lvl + 1;
                temp->level_final = max(temp->level_final, temp->level);
                order.push(temp);
                if (temp->level > largest->level){
                    largest = temp;
                }
                temp->pushed = true;
            }
        }
    }
    return largest;
}

int main() {
    fio();
    ll n;
    cin>>n;
    node* tree[n];
    for (ll i=0; i<n; i++){
        node* gm = new node;
        gm->id = i;
        tree[i] = gm;
    }

    for (ll i=1; i<n; i++){
        ll a,b;
        cin>>a>>b;
        tree[a-1]->neighbours.pb(tree[b-1]);
        tree[b-1]->neighbours.pb(tree[a-1]);
    }

    node* v1 = dfs_level(tree[0]);
    for (ll i=0; i<n; i++){
        tree[i]->pushed = false;
    }
    node* v2 = dfs_level(v1);
    for (ll i=0; i<n; i++){
        tree[i]->pushed = false;
    }
    node* temp = dfs_level(v2);
    for (ll i=0; i<n; i++){
        cout<<tree[i]->level_final<<" ";
    }
}