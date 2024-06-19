#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#define ll long long int

using namespace std;

int main() {
    ll n;
    cin>>n;
    vector <int> values;
    for (ll i=0; i<n; i++){
        ll in;
        cin>>in;
        values.push_back(in);
    }
    ll rounds=1;
    vector <ll> indices(n+1);
    for (ll i=0; i<n; i++){
        indices[values[i]] = i;
    }

    for (ll i=0; i<n; i++){
        if (indices[i+1]<indices[i]){
            rounds++;
        }
    }
    cout<<rounds;
}