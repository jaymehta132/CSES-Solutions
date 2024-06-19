#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#define ll long long int

using namespace std;

int main() {
    ll n;
    cin>>n;
    vector <ll> values;
    for (ll i=0; i<n; i++){
        ll in;
        cin>>in;
        values.push_back(in);
    }
    
    ll sum=0;
    ll ans=-1e9;
    for (ll i=0; i<n; i++){
        sum+=values[i];
        ans = max(sum, ans);
        if (sum<0){
            sum=0;
        }
    }
    cout<<ans;
}