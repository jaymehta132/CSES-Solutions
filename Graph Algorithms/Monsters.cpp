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

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int main() {
    ll n,m;
    cin>>n>>m;
    vector <pair<ll,ll>> monster;
    pair<ll,ll> start;
    vector <vector<char>> grid(n, vector<char>(m));
    for (ll i=0; i<n; i++){
        for (ll j=0; j<m; j++){
            char in;
            cin>>in;
            grid[i][j] = in;
            if (in == 'M'){
                monster.pb(mp(i,j));
            }
            if (in == 'A'){
                start = mp(i,j);
            }
        }
    }

    ll mon_moves[n][m];
    bool mon_pushed[n][m];
    ll a_moves[n][m];
    bool a_pushed[n][m];

    for (ll i=0; i<n; i++){
        for (ll j=0; j<m; j++){
            mon_moves[i][j] = 1e9;
            a_moves[i][j] = 1e9;
            mon_pushed[i][j] = false;
            a_pushed[i][j] = false;
        }
    }
    queue <pair<ll,ll>> order;
    for (ll i=0; i<monster.size(); i++){
        mon_moves[monster[i].first][monster[i].second] = 0;
        order.push(monster[i]);
        mon_pushed[monster[i].first][monster[i].second] = true;
    }

    while (!order.empty()){
        pair<ll,ll> current = order.front();
        order.pop();
        ll i = current.first;
        ll j = current.second;
        if (i>0 && grid[i-1][j] != '#' && !mon_pushed[i-1][j]){
            mon_moves[i-1][j] = min(mon_moves[i-1][j], mon_moves[i][j]+1);
            pair <ll,ll> new_coordinates = make_pair(i-1,j);
            if (!mon_pushed[i-1][j]){
                order.push(new_coordinates);
                mon_pushed[i-1][j] = true;
            }
        }
        if (j>0 && grid[i][j-1] != '#' && !mon_pushed[i][j-1]){
            mon_moves[i][j-1] = min(mon_moves[i][j-1], mon_moves[i][j]+1);
            pair <ll,ll> new_coordinates = make_pair(i,j-1);
            if (!mon_pushed[i][j-1]){
                order.push(new_coordinates);
                mon_pushed[i][j-1] = true;
            }
        }
        if (i<n-1 && grid[i+1][j] != '#' && !mon_pushed[i+1][j]){
            mon_moves[i+1][j] = min(mon_moves[i+1][j], mon_moves[i][j]+1);
            pair <ll,ll> new_coordinates = make_pair(i+1,j);
            if (!mon_pushed[i+1][j]){
                order.push(new_coordinates);
                mon_pushed[i+1][j] = true;
            }
        }
        if (j<m-1 && grid[i][j+1] != '#' && !mon_pushed[i][j+1]){
            mon_moves[i][j+1] = min(mon_moves[i][j+1], mon_moves[i][j]+1);
            pair <ll,ll> new_coordinates = make_pair(i,j+1);
            if (!mon_pushed[i][j+1]){
                order.push(new_coordinates);
                mon_pushed[i][j+1] = true;
            }
        }
    }
    
    queue <pair<ll,ll>> new_order;
    new_order.push(start);
    a_moves[start.first][start.second] = 0;
    a_pushed[start.first][start.second] = true;
    pair<ll,ll> end;
    while (!new_order.empty()){
        pair<ll,ll> current = new_order.front();
        new_order.pop();
        ll i = current.first;
        ll j = current.second;
        if (i>0 && grid[i-1][j] != '#' && !a_pushed[i-1][j] && mon_moves[i-1][j]>a_moves[i][j]+1){
            a_moves[i-1][j] = min(a_moves[i-1][j], a_moves[i][j]+1);
            pair <ll,ll> new_coordinates = make_pair(i-1,j);
            if (!a_pushed[i-1][j]){
                new_order.push(new_coordinates);
                a_pushed[i-1][j] = true;
            }
            if (i-1==0){
                end = new_coordinates;
                break;
            }
        }
        if (j>0 && grid[i][j-1] != '#' && !a_pushed[i][j-1] && mon_moves[i][j-1]>a_moves[i][j]+1){
            a_moves[i][j-1] = min(a_moves[i][j-1], a_moves[i][j]+1);
            pair <ll,ll> new_coordinates = make_pair(i,j-1);
            if (!a_pushed[i][j-1]){
                new_order.push(new_coordinates);
                a_pushed[i][j-1] = true;
            }
            if (j-1==0){
                end = new_coordinates;
                break;
            }
        }
        if (i<n-1 && grid[i+1][j] != '#' && !a_pushed[i+1][j] && mon_moves[i+1][j]>a_moves[i][j]+1){
            a_moves[i+1][j] = min(a_moves[i+1][j], a_moves[i][j]+1);
            pair <ll,ll> new_coordinates = make_pair(i+1,j);
            if (!a_pushed[i+1][j]){
                new_order.push(new_coordinates);
                a_pushed[i+1][j] = true;
            }
            if (i+1==n-1){
                end = new_coordinates;
                break;
            }
        }
        if (j<m-1 && grid[i][j+1] != '#' && !a_pushed[i][j+1] && mon_moves[i][j+1]>a_moves[i][j]+1){
            a_moves[i][j+1] = min(a_moves[i][j+1], a_moves[i][j]+1);
            pair <ll,ll> new_coordinates = make_pair(i,j+1);
            if (!a_pushed[i][j+1]){
                new_order.push(new_coordinates);
                a_pushed[i][j+1] = true;
            }
            if (j+1==m-1){
                end = new_coordinates;
                break;
            }
        }
    }
    if (start.first==0 || start.first==n-1 || start.second==0 || start.second==m-1){
        cout<<"YES"<<"\n";
        cout<<"0";
    }
    else if (new_order.empty()){
        cout<<"NO";
    }
    else{
        cout<<"YES"<<"\n";
        pair <ll, ll> coordinates = end;
        stack <char> q_final;
        while (coordinates != start){
            ll i = coordinates.first;
            ll j = coordinates.second;
            ll count = a_moves[i][j];
            if (i>0 && a_moves[i-1][j] == count - 1 && grid[i-1][j] != '#') {
                q_final.push('D');
                coordinates = make_pair(i-1, j);
            }
            else if (i<n-1 && a_moves[i+1][j] == count - 1 && grid[i+1][j] != '#') {
                q_final.push('U');
                coordinates = make_pair(i+1, j);
            }
            else if (j>0 && a_moves[i][j-1] == count - 1 && grid[i][j-1] != '#') {
                q_final.push('R');
                coordinates = make_pair(i, j-1);
            }
            else if (j<m-1 && a_moves[i][j+1] == count - 1 && grid[i][j+1] != '#') {
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