#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
#define ll long long int

using namespace std;

int main() {
    ll n,x;
    cin>>n>>x;
    vector <ll> coins;
    for (ll i=0; i<n; i++){
        ll in;
        cin>>in;
        coins.push_back(in);
    }

    vector <ll> minimum(x+1);
    for (ll i=0; i<=x; i++){
        minimum[i] = 1e9;
    }

    minimum[0] = 0;
    for (ll i=1; i<=x; i++){
        for (ll j=0; j<n; j++){
            if (coins[j]>i || minimum[i - coins[j]] == 1e9){
                continue;
            }
            else{
                minimum[i] = min(minimum[i], minimum[i - coins[j]]+1);
            }
        }
    }

    if (minimum[x]!= 1e9){
        cout<<minimum[x];
    }
    else{
        cout<<"-1";
    }
}