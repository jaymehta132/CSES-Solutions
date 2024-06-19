#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    unsigned long long int n;
    cin>>n;
    vector <int> arr;
    for (int i = 0; i<n; i++){
        int in;
        cin>>in;
        arr.push_back(in);
    }
    set <int> values;
    for (int i=0; i<n; i++){
        values.insert(arr[i]);
    }
    cout<<values.size();
}