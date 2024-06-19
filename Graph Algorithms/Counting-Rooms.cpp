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

int main() {
    int n,m;
    cin>>n>>m;
    int id[n][m];
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            char in;
            cin>>in;
            if (in == '.'){
                id[i][j] = 0;
            }
            else{
                id[i][j] = -1;
            }
        }
    }

    bool pushed[n][m];
    for (ll i=0; i<n; i++){
        for (ll j=0; j<m; j++){
            pushed[i][j] = false;
        }
    }

    int count=1;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (id[i][j] == 0){
                stack <pair<int,int>> order;
                order.push(make_pair(i,j));
                while(!order.empty()){
                    pair<int, int> p = order.top();
                    order.pop();
                    id[p.first][p.second] = count;
                    if (p.first > 0 && id[p.first - 1][p.second] == 0) {
                        
                        order.push({p.first - 1,p.second});
                    }
                    if (p.first < n - 1 && id[p.first + 1][p.second] == 0){
                        order.push({p.first + 1,p.second});
                    }
                    if (p.second > 0 && id[p.first][p.second - 1] == 0) {
                        order.push({p.first,p.second - 1});
                    }
                    if (p.second < m - 1 && id[p.first][p.second + 1] == 0){
                        order.push({p.first,p.second + 1});
                    }
                }
                count++;
            }
        }
    }
    cout<<count-1;
}