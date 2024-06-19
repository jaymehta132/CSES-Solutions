#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define ll long long int
using namespace std;

void solve(vector <vector <ll>> vec, ll n, ll x){
    for (ll ptr1=0; ptr1<n-2; ptr1++){
        ll ptr2 = ptr1+1;
        ll ptr3 = n-1;
        while(ptr2<ptr3){
            ll sum = vec[ptr1][0] + vec[ptr2][0] + vec[ptr3][0];
            if (sum==x){
                cout<<vec[ptr1][1]<<" "<<vec[ptr2][1]<<" "<<vec[ptr3][1];
                return;
            }
            else if (sum<x){
                ptr2++;
            }
            else if (sum>x){
                ptr3--;
            }
        }
    }
    cout<<"IMPOSSIBLE";
}


int main() {
    ll n, x;
    cin>>n>>x;
    vector <int> values;
    for (ll i=0; i<n; i++){
        ll in;
        cin>>in;
        values.push_back(in);
    }

    vector <vector <ll>> vec(n, vector <ll>(2));
    for (ll i=0; i<n; i++){
        vec[i][0]=values[i];
        vec[i][1]=i+1;
    }

    sort(vec.begin(), vec.end());
    solve(vec, n, x);
}