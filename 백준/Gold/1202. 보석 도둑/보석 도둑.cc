#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

priority_queue<ll> pq;
vector<pair<ll,ll>> jewel;
vector<ll> bag;
ll n, k, max_m;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        ll m, v;
        cin >> m >> v;

        jewel.push_back({m, v});

    }
    for (int i = 0; i < k; i++) {
        ll a;
        cin >> a;
        bag.push_back(a);
    }
    ll sum = 0;
    sort(bag.begin(), bag.end());
    sort(jewel.begin(), jewel.end());

    int idx = 0;

    for (int i = 0; i < bag.size(); i++) {

        while (jewel[idx].first <= bag[i] && idx < jewel.size()) {

            pq.push(jewel[idx].second);
            idx++;
        }

        if (!pq.empty()) {
            ll cur_value = pq.top();

            sum += cur_value;
            pq.pop();
        }

    }

    cout << sum;



    return 0;
}