#include <iostream>

using namespace std;

int main() {
    unsigned long long int n, x, temp;
    cin>>n;
    temp = n;
    x = 0;
    while (temp >0) {
        temp /= 5;
        x += temp;
    }
    cout<<x;
}