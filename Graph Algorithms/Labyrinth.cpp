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

struct info{
    int no_of_moves;
    pair <ll, ll> coordinates;
};

int main() {
    ll h, w;
    cin>>h>>w;
    char grid[h][w];
    pair <ll,ll> start, end;
    for (ll i=0; i<h; i++){
        for (ll j=0; j<w; j++){
            char in;
            cin>>in;
            grid[i][j] = in;
            if (in=='A'){
                start = make_pair(i, j);
            }
            else if(in=='B'){
                end = make_pair(i, j);
            }
        }
    }

    ll moves[h][w];
    bool visited[h][w];
    bool pushed[h][w];
    for (ll i=0; i<h; i++){
        for (ll j=0; j<w; j++){
            moves[i][j] = 1e9;
            visited[i][j] = false;
            pushed[i][j] = false;
        }
    }
    moves[start.first][start.second] = 0;
    stack <char> q_final;

    queue <info> order;
    info start_pt;
    start_pt.no_of_moves = 0;
    start_pt.coordinates = start;
    order.push(start_pt);
    pushed[start.first][start.second] = true;

    while (!order.empty()){
        info current_pt = order.front();
        pair <ll, ll> coordinates = current_pt.coordinates;
        ll i = coordinates.first;
        ll j = coordinates.second;
        visited[i][j] = true;
        ll no_of_moves = current_pt.no_of_moves;
        if (i>0 && grid[i-1][j] != '#' && !pushed[i-1][j]){
            moves[i-1][j] = min(moves[i-1][j], no_of_moves+1);
            pair <ll,ll> new_coordinates = make_pair(i-1,j);
            if (new_coordinates == end){
                break;
            } 
            info new_pt;
            new_pt.no_of_moves = moves[i-1][j];
            new_pt.coordinates = new_coordinates;
            if (!pushed[i-1][j]){
                order.push(new_pt);
                pushed[i-1][j] = true;
            }
        }

        if (j>0 && grid[i][j-1] != '#' && !pushed[i][j-1]){
            moves[i][j-1] = min(moves[i][j-1], no_of_moves+1);
            pair <ll,ll> new_coordinates = make_pair(i,j-1);
            if (new_coordinates == end){
                break;
            } 
            info new_pt;
            new_pt.no_of_moves = moves[i][j-1];
            new_pt.coordinates = new_coordinates;
            if (!pushed[i][j-1]){
                order.push(new_pt);
                pushed[i][j-1] = true;
            }
        }

        if (i<h-1 && grid[i+1][j] != '#' && !pushed[i+1][j]){
            moves[i+1][j] = min(moves[i+1][j], no_of_moves+1);
            pair <ll,ll> new_coordinates = make_pair(i+1,j);
            if (new_coordinates == end){
                break;
            } 
            info new_pt;
            new_pt.no_of_moves = moves[i+1][j];
            new_pt.coordinates = new_coordinates;
            if (!pushed[i+1][j]){
                order.push(new_pt);
                pushed[i+1][j] = true;
            }
        }

        if (j<w-1 && grid[i][j+1] != '#' && !pushed[i][j+1]){
            moves[i][j+1] = min(moves[i][j+1], no_of_moves+1);
            pair <ll,ll> new_coordinates = make_pair(i,j+1);
            if (new_coordinates == end){
                break;
            } 
            info new_pt;
            new_pt.no_of_moves = moves[i][j+1];
            new_pt.coordinates = new_coordinates;
            if (!pushed[i][j+1]){
                order.push(new_pt);
                pushed[i][j+1] = true;
            }
        }
        order.pop();
    }

    if (order.empty()){
        cout<<"NO";
    }
    else{
        cout<<"YES"<<"\n";
        pair <ll, ll> coordinates = end;
        while (coordinates != start){
            ll i = coordinates.first;
            ll j = coordinates.second;
            ll count = moves[i][j];
            if (i>0 && moves[i-1][j] == count - 1 && grid[i-1][j] != '#') {
                q_final.push('D');
                coordinates = make_pair(i-1, j);
            }
            else if (i<h-1 && moves[i+1][j] == count - 1 && grid[i+1][j] != '#') {
                q_final.push('U');
                coordinates = make_pair(i+1, j);
            }
            else if (j>0 && moves[i][j-1] == count - 1 && grid[i][j-1] != '#') {
                q_final.push('R');
                coordinates = make_pair(i, j-1);
            }
            else if (j<w-1 && moves[i][j+1] == count - 1 && grid[i][j+1] != '#') {
                q_final.push('L');
                coordinates = make_pair(i, j+1);
            }
        }
        cout<<q_final.size()<<"\n";
        while(!q_final.empty()){
            cout<<q_final.top();
            q_final.pop();
        }
    }
}