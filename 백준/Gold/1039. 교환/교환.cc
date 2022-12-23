#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;


int visited[1000001];
int nv[10];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;

    cin >> n >> k;

    string s = to_string(n);
    bool check = false;
    for(int i = 0; i < s.size(); i++)
    {
        nv[s[i] - '0']++;
        if(nv[s[i] - '0'] > 1){
            check = true;
        }
    }


    queue<pair<string,int>> q; // 만든숫자, 바꾼 횟수

    q.push({to_string(n), 0});

    //visited[n] = 1;
    int ans = -1;
    int tans = -1;

    while (!q.empty()) {

        string num = q.front().first;
        int cnt = q.front().second;

        q.pop();




        // 같은 위치를 또 바꿀 수도 있다.
        // cnt가 1 이상일 때 남은 바꾸는 횟수(k - change_num)가 짝수일 경우에는 해당 ans가 제일 큰 수가 된다.

        if (cnt >= 1) {
            //cout << num << "\n";
            int to_num = stoi(num);


            if (ans < to_num) {
                // 1-1. (k-cnt) 바꾼 숫자가 최대일 경우 바꿨다가 다시 바꾸는 경우
                if ((k - cnt) % 2 == 0) {
                    ans = max(ans, to_num);
                }
                // 1-2. cnt가 k일 때 최대인 경우
                if (cnt == k) {
                    ans = max(ans, to_num);
                }
                // 1-3. 바꾼 횟수와 상관없이 제일 큰 수
                // tans가 답이 되려면 같은 숫자가 2개 이상 있어야 한다.
                tans = max(tans, to_num);
            }

        }

        if(cnt + 1> k) continue;

        string tmp = num;
        for (int i = 0; i < num.size() - 1; i++) {
            for (int j = i + 1; j < num.size(); j++) {
                tmp = num;
                if (i == 0) {
                    if(tmp[j] == '0') continue;
                }
                // 위치 바꾸기
                char a = tmp[i];
                tmp[i] = tmp[j];
                tmp[j] = a;



                if (!visited[stoi(tmp)]) {
                    visited[stoi(tmp)] = 1;
                    q.push({tmp, cnt + 1});
                }

            }

        }


    }

    if(check){
        cout << tans;
    }else
        cout << ans;





            return 0;
    }