#include <iostream>

using namespace std;

int main() {
    unsigned long long int n;
    cin>>n;
    unsigned long long int x = 1;
    for (int i=0; i<n; i++){
        x = (x*2) % (1000000007);
    }
    cout<<x;
    return 0;
}