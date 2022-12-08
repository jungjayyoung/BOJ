#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


vector<pair<int,int>> v;

int dest, oil;

priority_queue<int> pq;

bool cmp(pair<int, int> a, pair<int, int> b){

    if (a.first != b.first) {
        return a.first < b.first;
    }else
        return a.second > b.second;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});    //first: 주요소까지거리, second: 주요소에서 얻을 수 있는 연료
    }

    cin >> dest >> oil;

    //일단 거리순으로 정렬
    sort(v.begin(), v.end(), cmp);

    int next; //다음에 추가할 주요소의 인덱스 저장
    //1. 먼저 처음에 가지고 있는 오일로 갈 수 있는 주요소를 우선순위 큐에 담는다
    for (int i = 0; i < n; i++) {

        if (v[i].first <= oil) {
            pq.push(v[i].second);
            next = i;
        }

    }

    next = next +1; // 다음에 추가할 주요소 인덱스 저장

    int cnt = 0;

    while (!pq.empty()) {

        // 2. 현재 오일로 목적지 도달 가능한지 체크
        if (oil >= dest) {
            cout << cnt;
            return 0;
        }

        //3. 우선순위 큐로부터 멈출 주요소에서 기름을 담는다

        oil += pq.top();
        cnt++;
        pq.pop();

        //4. 담은 기름으로 다음에 갈 수 있는 주요소들을 우선순위 큐에 담는다
        while (next < n && v[next].first <= oil) {
            pq.push(v[next].second);
            next++;
        }

    }


    // while 문 밖으로 나가면 갈 수 없다는 뜻
    cout << -1;

    return 0;
}