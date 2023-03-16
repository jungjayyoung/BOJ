#include <iostream>
#include <algorithm>

using namespace std;


int n, m;


int days[51];



int is_friend[51][51];




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    fill(&is_friend[0][0], &is_friend[51][0], 123456789);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        is_friend[a][b] = 0;
        is_friend[b][a] = 0;
    }


    int cnt = m;
    int day = 1;

    while (cnt < n * (n - 1) / 2) {

        // 친구
        for (int i = 1; i <= n; i++) {

            // 주인공
            for (int j = 1; j <= n; j++) {

                // 친구의 친구
                for (int k = 1; k <= n; k++) {
                    if(i == j || j == k || i == k) continue;

                    if (is_friend[j][k] == 123456789 && is_friend[j][i] < day && is_friend[i][k] < day) {

                        is_friend[j][k] = is_friend[k][j] = day;
                        days[day]++;
                        cnt++;
                    }

                }
            }
        }



        day++;

    }


    cout << day - 1 << "\n";

    for (int i = 1; i < day; i++) {
        cout << days[i] << "\n";
    }


    return 0;
}