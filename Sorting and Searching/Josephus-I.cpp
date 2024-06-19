#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long int

using namespace std;

int main() {
    ll n;
    cin>>n;
    queue <ll> q;
    for (ll i=0; i<n; i++){
        q.push(i+1);
    }

    bool flag = false;
    while(!q.empty()){
        ll in = q.front();
        q.pop();
        if (flag){
            cout<<in<<" ";
        }
        else{
            q.push(in);
        }
        flag = !flag;
    }
}