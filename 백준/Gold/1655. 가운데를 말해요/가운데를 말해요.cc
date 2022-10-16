#include <iostream>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int> pq_max;
priority_queue<int,vector<int>,greater<>> pq_min;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {

        int num;
        cin >> num;
        if (pq_max.size() == pq_min.size()) {
            pq_max.push(num);
        }else{
            pq_min.push(num);
        }

        if (!pq_max.empty() && !pq_min.empty() && (pq_max.top() > pq_min.top())) {
            int tmp1 = pq_max.top();
            int tmp2 = pq_min.top();

            pq_min.pop();
            pq_max.pop();

            pq_min.push(tmp1);
            pq_max.push(tmp2);

        }

        cout << pq_max.top() << "\n";

    }




    return 0;
}