#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    long long int n, m;
    cin>>n>>m;
    multiset <int> prices;
    for (int i=0; i<n; i++){
        long long int in;
        cin>>in;
        prices.insert(in);
    }
    for (int j=0; j<m; j++){
        long long int input;
        cin>>input;
        auto it = prices.upper_bound(input);
        if (it != prices.begin()){
            --it;
            if (*it <= input) {
                cout << *it<<"\n";
                prices.erase(prices.lower_bound(*it));
            } 
            else {
                cout << "-1"<<"\n";
            }
        }
        else {
            cout<<"-1"<<"\n";
        }
    }
}