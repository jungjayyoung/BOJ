#include <iostream>
#include <queue>
#include <functional>
#include <vector>

using namespace std;

int visited[1000001];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int t;

    cin >> t;


    for (int i = 0; i < t; i++) {

        int k;
        cin >> k;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq2;
        priority_queue<pair<int,int>> pq1;
        int idx = 1;
        fill(visited, visited + 1000001, 0);

        for (int j = 0; j < k; j++) {

            char s;
            int num;
            cin >> s >> num;

            if (s == 'I') {


                pq1.push({num, idx});
                pq2.push({num, idx});
                idx++;

            } else if (s == 'D') {

                //pq1 이 최대값, pq2가 최소값
                if (num == -1) {

                    while (!pq2.empty() && visited[pq2.top().second]) {
                        pq2.pop();
                    }

                    if(pq2.empty()) continue;

                    int tmp = pq2.top().second;
                    pq2.pop();
                    visited[tmp] = 1;
                } else if (num == 1) {
                    while(!pq1.empty() && visited[pq1.top().second]) {
                        pq1.pop();
                    }
                    if(pq1.empty()) continue;
                    int tmp = pq1.top().second;
                    pq1.pop();
                    visited[tmp] = 1;
                }

            }


        }

        while (!pq2.empty() && visited[pq2.top().second]) {
            pq2.pop();
        }

        while(!pq1.empty() && visited[pq1.top().second]) {
            pq1.pop();
        }

        if (pq1.empty() && pq2.empty()) {
            cout << "EMPTY" << "\n";
        } else{
            cout << pq1.top().first << " " << pq2.top().first << "\n";
        }


    }


    return 0;
}