#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long int

using namespace std;

int main() {
    ll n;
    cin>>n;
    vector <ll> arrivals, departures;
    for (ll i=0; i<n; i++){
        ll a,d;
        cin>>a>>d;
        arrivals.push_back(a);
        departures.push_back(d);
    }
    vector <vector<ll>> vec(n, vector<ll>(3));
    for (ll i=0; i<n; i++){
        vec[i][0] = arrivals[i];
        vec[i][1] = departures[i];
        vec[i][2] = i;
    }

    sort(vec.begin(), vec.end());
    priority_queue <pair<ll, ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> Rooms;

    ll count=0;
    vector <ll> ans(n);
    for (ll i=0; i<n; i++){
        ll arrival = vec[i][0];
        ll departure = vec[i][1];
        ll idx = vec[i][2];

        if (Rooms.empty() || Rooms.top().first>=arrival){
            count+=1;
            Rooms.push(make_pair(departure, count));
            ans[idx] = count;
        }
        else {
            ll vacant = Rooms.top().second;
            Rooms.pop();
            Rooms.push(make_pair(departure, vacant));
            ans[idx] = vacant;
        }
    }
    cout<<count<<"\n";
    for (ll i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
}