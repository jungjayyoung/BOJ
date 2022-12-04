#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

// 1. 마감일이 짧은 것을 우선
// 2. 마감일이 동일할 경우 점수가 높은 것으로

vector<pair<int,int>> v;

bool cmp(pair<int,int> a, pair<int,int> b){

    if (a.first != b.first) {
        return a.first < b.first;
    }else{
        return a.second > b.second;
    }

}

struct cmp2{
    bool operator()(pair<int,int> a,pair<int,int> b){
        if (a.second == b.second) {
            return a.first > b.first;
        }else{
            return a.second > b.second;
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int d, w;
        cin >> d >> w;
        v.push_back({d, w});
    }

    sort(v.begin(), v.end(), cmp);

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp2> pq;

    for (int i = 0; i < v.size(); i++) {

        // 1. 마감일이 짧은 것을 먼저
       if (pq.size() < v[i].first) {
            pq.push({v[i].first, v[i].second});

            //2. 만약에 현재 pq의 탑보다 점수가 큰 경우
        } else if (pq.top().second < v[i].second) {
           pq.pop();
           pq.push({v[i].first, v[i].second});
        }
        //cout << v[i].first << " " << v[i].second << "\n";

    }

    int sum = 0;
    //cout << "\n";

    while (!pq.empty()) {
        //cout << pq.top().first << " " << pq.top().second << "\n";
        sum += pq.top().second;
        pq.pop();
    }

    cout << sum;

    return 0;
}