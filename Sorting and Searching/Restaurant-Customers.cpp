#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    long long int n;
    cin>>n;
    multiset <int> start;
    multiset <int> end;
    for (int i=0; i<n; i++){
        long long int a, b;
        cin>>a>>b;
        start.insert(a);
        end.insert(b);
    }
    int count = 0;
    int max = 0;
    int start_max = *(start.rbegin());
    int time = 0;
    while (time < start_max){
        if (*start.lower_bound(time) < *end.lower_bound(time)){
            time = *start.lower_bound(time);
            count += 1;
            start.erase(start.find(time));
            if (max < count){
                max = count;
            }
        }
        else if (*start.lower_bound(time) > *end.lower_bound(time)){
            time = *end.lower_bound(time);
            count -= 1;
            end.erase(end.find(time));
        }
        else {
            time = *start.lower_bound(time);
            start.erase(start.find(time));
            end.erase(end.find(time));
        }
    }
    cout<<max;
    return 0;
}