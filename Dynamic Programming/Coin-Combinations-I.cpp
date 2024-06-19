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

    vector <ll> ways(x+1);
    for (ll i=0; i<=x; i++){
        ways[i] = 0;
    }

    ways[0] = 1;
    ll mod = 1e9 + 7;
    for (ll i=1; i<=x; i++){
        for (ll j=0; j<n; j++){
            if (coins[j]<=i){
                ways[i] = (ways[i] + ways[i-coins[j]])%mod;
            }
        }
    }
    cout<<ways[x];
}