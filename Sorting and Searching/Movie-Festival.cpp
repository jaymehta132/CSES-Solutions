#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sortFunc(pair <int, int> &p1, pair <int, int> &p2){
    return p1.second < p2.second;
}

int main() {
    long long int n;
    cin>>n;
    vector <pair <int, int>> intervals;
    for (int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        intervals.push_back(make_pair(a, b));
    }
    sort(intervals.begin(), intervals.end(), sortFunc);
    int time=0;
    int count = 0;
    for (int i=0; i<n; i++){
        if (intervals[i].first>=time){
            count+=1;
            time = intervals[i].second;
        }
    }
    cout<<count;
} 