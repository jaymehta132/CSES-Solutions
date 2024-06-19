#include <set>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    multiset <int> distances;
    set <int> street;
    vector <int> ans;
    long long int x,n;
    cin>>x>>n;
    street.insert(0);
    street.insert(x);
    distances.insert(x);
    for (long long int i=0; i<n; i++){
        long long int in;
        cin >> in;
        auto next=street.upper_bound(in);
        auto prev = next;
        --prev;
        street.insert(in);
        distances.insert(in - *prev);
        distances.insert(*next - in);
        distances.erase(distances.lower_bound(*next - *prev));
        ans.push_back(*(distances.rbegin()));
        //cout<<*(distances.rbegin())<<" ";
    }

    for (long long int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
