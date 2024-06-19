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
    vector <ll> values;
    for (ll i=0; i<n; i++){
        ll in;
        cin>>in;
        values.push_back(in);
    }

    ll sum=0;
    map <ll, ll> sums;
    sums[0] = 1;
    ll count = 0; 
    for (ll i=0; i<n; i++){
        sum += values[i];
        count += sums[sum - x];
        sums[sum]+=1;
    }
    cout<<count;
}