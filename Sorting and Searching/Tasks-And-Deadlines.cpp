#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long int n;
    cin>>n;
    vector <int> duration, deadline;
    for (int i=0; i<n; i++){
        int a,d;
        cin>>a>>d;
        duration.push_back(a);
        deadline.push_back(d);
    }
    sort(duration.begin(), duration.end());
    long long int reward = 0;
    for (int i=0; i<n; i++){
        reward = reward + deadline[i] - (n-i)*duration[i];
    }
    cout<<reward;
}   