#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#define ll long long int

using namespace std;

void solve(vector <vector<ll>> vec, ll n, ll x){
    for (ll ptr1=0; ptr1<n-3; ptr1++){
        for (ll ptr2=ptr1+1; ptr2<n-2; ptr2++){
            ll ptr3 = ptr2+1;
            ll ptr4 = n-1;
            while (ptr3<ptr4){
                ll sum = vec[ptr1][0] + vec[ptr2][0] + vec[ptr3][0] + vec[ptr4][0];
                if (sum==x){
                    cout<<vec[ptr1][1]<<" "<<vec[ptr2][1]<<" "<<vec[ptr3][1]<<" "<<vec[ptr4][1];
                    return;
                }
                else if (sum<x){
                    ptr3++;
                }
                else if (sum>x){
                    ptr4--;
                }
            }
        }
    }
    cout<<"IMPOSSIBLE";
    return;
}

int main() {
    ll n,x;
    cin>>n>>x;
    vector <ll> values;
    for (ll i=0; i<n; i++){
        ll in;
        cin>>in;
        values.push_back(in);
    }
    
    vector <vector <ll>> vec(n, vector <ll>(2));
    for (ll i=0; i<n; i++){
        vec[i][0] = values[i];
        vec[i][1] = i+1;
    }
    sort(vec.begin(), vec.end());
    solve(vec, n, x);
}