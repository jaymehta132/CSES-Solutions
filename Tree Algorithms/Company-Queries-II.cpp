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

ll dp[MAX][21];

struct employee{
    ll id;
    employee* boss = nullptr;
    ll level = 1;
};

employee* LCA(employee* a, employee* b, employee* office[MAX]){
    if (a->level > b->level){
        employee* temp = a;
        a = b;
        b = temp;
    }
    ll d = b->level - a->level;

    employee* x = b;
    for (ll j=0; j<21; j++){
        if(d&(1<<j)){
            x = office[dp[x->id][j]];
        }
    }
    b = x;

    // this brings both nodes to equal level, need to do binary search now
    
    if (a == b) {
        return a;
    }

    // Binary lifting to find LCA
    for (ll j = 20; j >= 0; j--) {
        if (dp[a->id][j] != dp[b->id][j]) {
            a = office[dp[a->id][j]];
            b = office[dp[b->id][j]];
        }
    }

    // Now both are children of LCA
    return office[a->boss->id];
}

int main() {
    fio();
    ll n,q;
    cin>>n>>q;
    //cout<<"HELLO"<<endl;
    employee* office[MAX];
    employee* gm1 = new employee;
    gm1->id = 0;
    gm1->level = 0;
    office[0] = gm1;
    employee* gm2 = new employee;
    gm2->id = 1;
    gm2->boss = gm1;
    office[1] = gm2;
    dp[0][0] = 0;
    dp[1][0] = 0;
    for (ll i = 2; i<n+1; i++){
        ll a;
        cin>>a;
        dp[i][0] = a;
        employee* new_employee = new employee;
        new_employee->id = i;
        new_employee->boss = office[a];
        new_employee->level = office[a]->level + 1;
        office[i] = new_employee;
    }

    for (ll j=1; j<21; j++){
        for (ll i=0; i<n+1; i++){
            dp[i][j] = dp[dp[i][j-1]][j-1];
        }
    }

    vector <pair<ll,ll>> queries;
    for (ll i=0; i<q; i++){
        ll a,b;
        cin>>a>>b;
        queries.pb(mp(a,b));
    }
    
    for (ll i=0; i<q; i++){
        pair<ll,ll> current_query = queries[i];
        cout<<LCA(office[current_query.first], office[current_query.second], office)->id<<"\n";
    }
}