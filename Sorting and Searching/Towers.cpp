#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long int n;
    cin>>n;
    multiset <int> top;
    for (long long int i=0; i<n; i++){
        long long int in;
        cin>>in;
        auto it = top.upper_bound(in);
        if (it != top.end()){
            top.erase(it);
            top.insert(in);
        }
        else{
            top.insert(in);
        }
    }
    cout<<top.size();
}