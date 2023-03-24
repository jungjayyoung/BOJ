#include <iostream>
#include <queue>

using namespace std;


queue<int> truck;
queue<int> bridge;

int n, w, l;// 트럭의 개수, 다리의 길이, 다리의 최대 하중

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> w >> l;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        truck.push(num);
    }

    int cur_bridge_weight = 0;
    int ans = 0;
    while (1) {

        int weight = truck.front();

        if (bridge.size() == w && cur_bridge_weight != 0) {
            cur_bridge_weight -= bridge.front();
            bridge.pop();
        }

        if(bridge.size() < w) {

            if (cur_bridge_weight + weight <= l) {
                if (!truck.empty()) {
                    cur_bridge_weight = cur_bridge_weight + weight;
                    truck.pop();
                    bridge.push(weight);
                }else
                    bridge.push(0);

            }else{
                bridge.push(0);
            }
        }

        if (bridge.size() == w && cur_bridge_weight == 0) {
            ans++;
            break;
        }
        ans++;
    }
    cout << ans;

    return 0;
}