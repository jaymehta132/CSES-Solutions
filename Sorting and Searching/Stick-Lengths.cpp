#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long int n;
    cin>>n;
    vector <int> length;
    for (long long int i=0; i<n; i++){
        int in;
        cin>>in;
        length.push_back(in);
    }

    sort(length.begin(), length.end());
    long long int cost, cost1, cost2;
    cost = 0;
    cost1 = 0;
    cost2 = 0;
    if(n%2 == 1){
        long long int median = length[(n-1)/2];
        for (long long int i=0; i<n; i++){
            cost += abs(median - length[i]);
        }
    }
    else {
        long long int median1 = length[n/2];
        long long int median2 = length[n/2 - 1];
        double median = (length[n/2] + length[n/2 - 1])/2;
        for (long long int i=0; i<n; i++){
            cost1 += abs(median1 - length[i]);
            cost2 += abs(median2 - length[1]);
            cost += abs(median - length[i]);
        }
    }
    cout<<cost;
}