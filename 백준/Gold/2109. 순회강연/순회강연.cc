#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;


int n;
int arr[10001];

vector<pair<int,int>> v;

bool cmp(pair<int,int> a, pair<int,int> b){

    if (a.second != b.second) {
        return a.second < b.second;
    }else
        return a.first > b.first;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n;

    for (int i = 0; i < n; i++) {
        int p, d;
        cin >> p >> d;
        v.push_back({p, d});
    }

    // p: 강연료, d: 날짜

    //1. 날짜 순서로 오름차순 정렬을 먼저 한다.
    //2. 날짜가 동일하다면 돈액수가 더 많은 순으로 정렬한다.

    sort(v.begin(), v.end(), cmp);

    priority_queue<int, vector<int>, greater<>> pq;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        pq.push(v[i].first);
        if (pq.size() > v[i].second) {
            pq.pop();
        }
    }

    while (!pq.empty()) {

        sum += pq.top();
        pq.pop();
    }

    cout << sum;
    return 0;
}