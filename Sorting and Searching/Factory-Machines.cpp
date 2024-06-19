#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
#define ll long long int

using namespace std;

int main() {
    ll n,t;
    cin>>n>>t;
    vector <ll> machines;
    for (ll i=0; i<n; i++){
        ll in;
        cin>>in;
        machines.push_back(in);
    }
    ll low=1;
    ll high = (*min_element(machines.begin(), machines.end()))*t;
    ll ans;
    while (low<=high){
        ll mid = (low+high)/2;
        ll sum = 0;
        for (ll i=0; i<n; i++){
            sum += (mid/machines[i]);
        }
        if (sum>=t){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    cout<<ans;
    
}