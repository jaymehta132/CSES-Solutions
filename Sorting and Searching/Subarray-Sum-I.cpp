#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
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
    ll ptr1, ptr2;
    ptr1=0;
    ptr2=0;
    ll count=0;
    ll sum=values[ptr1];
    while(ptr1<n && ptr2<n){
        if (sum==x){
            count++;
            sum-=values[ptr1];
            ptr1++;         
        }
        else if (sum<x){
            ptr2++;
            sum+=values[ptr2];
        }
        else if(sum>x){
            sum-=values[ptr1];
            ptr1++;
        }
    }
    cout<<count;
}