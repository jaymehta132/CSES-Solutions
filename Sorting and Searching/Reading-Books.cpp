#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
#define ll long long int

using namespace std;

int main() {
    ll n;
    cin>>n;
    vector <ll> books;
    for (ll i=0; i<n; i++){
        ll in;
        cin>>in;
        books.push_back(in);
    }
    sort(books.begin(), books.end());
    ll max = books[n-1];
    ll sum = 0;
    for (ll i=0; i<n-1; i++){
        sum+=books[i];
    }
    ll time;
    if (sum>=max){
        time = sum+max;
    }
    else{
        time = 2*max;
    }
    cout<<time;
}