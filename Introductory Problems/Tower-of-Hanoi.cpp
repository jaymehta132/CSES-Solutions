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

void hanoi(int n, int start, int mid, int destination){
    if (n==0){
        return;
    }
    else{
        hanoi(n-1, start, destination, mid);
        cout<<start<<" "<<destination<<"\n";
        hanoi(n-1, mid, start, destination);
        return;
    }
}

int main() {
    int n;
    cin>>n;
    int moves = pow(2, n) - 1;
    cout<<moves<<"\n";
    hanoi(n, 1, 2, 3);
}