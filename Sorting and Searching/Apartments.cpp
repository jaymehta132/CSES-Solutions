#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#define ll long long int

using namespace std;

int main() {
    ll n,m,k;
    cin>>n>>m>>k;
    vector <ll> apartments;
    vector <ll> buyers;
    for (ll i=0; i<n; i++){
        ll in;
        cin>>in;
        buyers.push_back(in);
    }
    for (ll i=0; i<m; i++){
        ll in;
        cin>>in;
        apartments.push_back(in);
    }
    sort(buyers.begin(), buyers.end());
    sort(apartments.begin(), apartments.end());
    
    ll ptr1, ptr2;
    ptr1=0;
    ptr2=0;
    ll count=0;
    while(ptr1<n && ptr2<m){
        if (abs(buyers[ptr1]-apartments[ptr2])<=k){
            count+=1;
            ptr1+=1;
            ptr2+=1;
        }
        else if (buyers[ptr1]<apartments[ptr2]){
            ptr1+=1;
        }
        else if (apartments[ptr2]<buyers[ptr1]){
            ptr2+=1;
        }
    }
    cout<<count;
}