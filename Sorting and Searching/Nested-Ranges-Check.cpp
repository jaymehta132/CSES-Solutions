#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
#define ll long long int

using namespace std;

bool SortFunc (pair<pair<ll,ll>,ll>& a, pair<pair<ll,ll>,ll>& b){
    if (a.first.first==b.first.first){
        return a.first.second>b.first.second;
    }
    else return a.first.first<b.first.first;
}

int main() {
    ll n;
    cin>>n;
    vector <pair<pair<ll,ll>,ll>> ranges;
    for (ll i=0; i<n; i++){
        ll a,b;
        cin>>a>>b;
        ranges.push_back(make_pair(make_pair(a,b),i));
    }

    sort(ranges.begin(), ranges.end(), SortFunc);

    vector<ll> contains(n), contained(n);
    
    ll minEnd = 2e9;
    for (ll i=n-1;i>=0;i--){
        if (ranges[i].first.second>=minEnd){
            contains[ranges[i].second] = 1;
        }
        minEnd = min(minEnd, ranges[i].first.second);
    }

    ll maxEnd = 0;
    for (ll i=0; i<n; i++){
        if (ranges[i].first.second<=maxEnd){
            contained[ranges[i].second] = 1;
        }
        maxEnd = max(maxEnd, ranges[i].first.second);
    }
    for (ll i=0; i<n; i++){
        cout<<contains[i]<<" ";
    }
    cout<<"\n";
    for (ll i=0; i<n; i++){
        cout<<contained[i]<<" ";
    }
}