#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long int n, x;
    cin>>n>>x;
    multiset <int> weights;
    for (long long int i=0; i<n; i++) {
        int in;
        cin>>in;
        weights.insert(in);
    }
    long long int count=0;
    while (weights.empty()== false){
        auto heaviest = prev(weights.end());
        int weight1 = *heaviest;
        weights.erase(heaviest);

        // Try to find the lightest weight that can be paired with the heaviest weight
        auto it = weights.upper_bound(x - weight1);
        if (it != weights.begin()) {
            --it; // Step back to the largest possible pairable weight
            if (*it <= x - weight1) {
                weights.erase(it);
            }
        }

        count += 1;
    }
    cout<<count;
}
