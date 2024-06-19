#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
#define ll long long int

using namespace std;

int main() {
    ll n;
    cin>>n;
    vector <ll> ways(n+1);
    ways[0] = 1;
    ll mod = 1e9 + 7;
    for  (ll i=1; i<=n; i++){
        for (ll j=1; j<=i && j<=6; j++){
            ways[i] = (ways[i] + ways[i-j])%mod;
        }
    }
    cout<<ways[n];
}