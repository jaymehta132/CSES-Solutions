#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#define ll long long int

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

void solution(ll n){
    if (((n)*(n+1))%4 != 0){
        cout<<"NO";
        return;
    }
    vector <ll> set1;
    vector <ll> set2;
    if (n%4==0){
        for (ll i=0; i<n; i=i+2){
            if (i%4==0){
                set1.push_back(i+2);
                set2.push_back(i+1);
            }
            else{
                set1.push_back(i+1);
                set2.push_back(i+2);
            }
        }
    }
    else{
        set1.push_back(1);
        set1.push_back(2);
        set2.push_back(3);
        for (ll i=3; i<n; i=i+2){
            if (i%4==3){
                set1.push_back(i+2);
                set2.push_back(i+1);
            }
            else{
                set1.push_back(i+1);
                set2.push_back(i+2);
            }
        }
    }
    cout<<"YES"<<"\n";
    cout<<set1.size()<<"\n";
    for (ll i=0; i<set1.size(); i++){
        cout<<set1[i]<<" ";
    }
    cout<<"\n";
    cout<<set2.size()<<"\n";
    for (ll i=0; i<set2.size(); i++){
        cout<<set2[i]<<" ";
    }
    return;
}


int main() {
    ll n;
    cin>>n;
    solution(n);
}