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
    set <ll> seq;
    for (ll i=0; i<n; i++){
        ll in;
        cin>>in;
        values.push_back(in);
    }
    ll ptr1=0;
    ll ptr2=0;
    ll ans=0;
    while(ptr2<n){
        if (seq.find(values[ptr2])==seq.end()){
            seq.insert(values[ptr2]);
            ll size = seq.size();
            ans = max(size, ans);
            ptr2++;
        }
        else if (seq.find(values[ptr2]) !=seq.end()){
            seq.erase(values[ptr1]);
            ptr1++;
        }
    }
    cout<<ans;
}

