#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int card[100001];

priority_queue<int,vector<int>,greater<>> q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> card[i];
        q.push(card[i]);
    }

    int sum = 0;

    while(q.size() != 1){
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();

        sum += a + b;

        q.push(a + b);

    }

    cout << sum;


}