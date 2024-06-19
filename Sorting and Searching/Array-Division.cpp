#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#define ll long long int

using namespace std;

ll search(vector <ll> values, ll low_value, ll high_value, ll n, ll k){
    ll low = low_value;
    ll high =  high_value;
    ll ans;
    while (low<=high){
        ll mid = (low+high)/2;
        ll count = 1;
        ll sub_sum=0;
        for (ll i=0; i<n; i++){
            sub_sum+=values[i];
            if (sub_sum>mid){
                sub_sum=values[i];
                count +=1;
            }
        }
        if (count<=k){
            high = mid-1;
            ans = mid;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

int main() {
    ll n,k;
    cin>>n>>k;
    vector <ll> values;
    ll sum=0;
    for (ll i=0; i<n; i++){
        ll in;
        cin>>in;
        values.push_back(in);
        sum+=in;
    }
    ll low = *max_element(values.begin(), values.end());
    ll high = sum;
    ll ans = search (values, low, high, n, k);
    cout<<ans;
}