#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

bool not_prime[10001]= {1,1,0};
int visited[10001];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    string a, b;

    int t;
    cin >> t;


    for (int i = 2; i <= 10000; i++) {

        if (not_prime[i] == 0) {

            for (int j = i * 2; j <= 10000; j += i) {
                not_prime[j] = 1;
            }
        }
    }


    while(t--) {
        fill(visited, visited + 10000, 0);
        cin >> a >> b;
        queue<pair<string, int>> q;

        q.push({a, 0});

        int aa = stoi(a);
        visited[aa] = 1;
        bool check = false;
        while (!q.empty()) {

            string cur_s = q.front().first;
            int cnt = q.front().second;

            q.pop();
            if (cur_s == b) {
                cout << cnt << "\n";
                check = true;
                break;

            }

            for (int i = 0; i <= 9; i++) {

                for (int j = 0; j < 4; j++) {
                    string tmp = cur_s;
                    if (i == 0 && j == 0) continue;

                    if(cur_s[j] - '0' == i) continue;


                    tmp[j] = i + '0';
                    int num = stoi(tmp);

                    if (!visited[num] && not_prime[num] == 0) {
                        visited[num] = 1;
                        q.push({tmp, cnt + 1});
                    }

                }

            }


        }

        if (!check) {
            cout << "Impossible" << "\n";
        }


    }


    return 0;
}