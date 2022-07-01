#include <iostream>
#include <algorithm>
#include <vector>



using namespace std;

bool notprime[4000001] = {1, 1, 0};

vector<int> v;


void solve(){

    for (int i = 2; i <= 4000000; i++) {

        if (!notprime[i]) {

            for (int j = i * 2; j <= 4000000; j += i) {
                notprime[j] = 1;
            }

        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    solve();

    for (int i = 2; i <= n; i++) {
        if (!notprime[i]) {
            v.push_back(i);
        }
    }

    int s = 0;
    int e = 0;
    int cnt = 0;
    

    if (n == 1) {
        cout << 0;
        return 0;
    }
    int sum = v[0];

    while (s < v.size()  || e < v.size() ) {


        if (s == e) {



            if (sum == n) {
                cnt++;

                sum -= v[s];
                if (s != v.size() - 1) {
                    s++;
                }
                if (e != v.size() - 1) {
                    e++;
                }

                continue;
            }

            if (s == v.size() - 1) {
                break;
            }
            if (e != v.size() - 1) {
                e++;
                sum += v[e];
            }
            continue;
        }

        if (sum < n) {
            if (e != v.size() - 1) {
                e++;
                sum += v[e];
            }

        } else if (sum > n) {

            if (s != v.size() - 1) {
                sum -= v[s];
                s++;
            }
        } else if (sum == n) {


            cnt++;
            if (s != v.size() - 1) {
                sum -= v[s];
                s++;
            }
            if (e != v.size() - 1) {
                e++;
                sum += v[e];
            }
        }

    }


    cout << cnt;
    return 0;
}