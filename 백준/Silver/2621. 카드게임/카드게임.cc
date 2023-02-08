#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

bool check[10];
int sum[10];

vector<int> num;
set<char> cl;
bool num_continue = true;
int num_count[10];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 5; i++) {
        char c;
        int n;
        cin >> c >> n;
        num.push_back(n);
        num_count[n]++;
        cl.insert(c);
    }

    sort(num.begin(), num.end());

    for (int i = 1; i < 5; i++) {
        if (num[i - 1] + 1 != num[i]) {
            num_continue = false;
            break;
        }
    }
    if (num_continue && cl.size() == 1) {
        sum[1] = 900 + num[4];
    }

    bool check2 = false;
    bool check22 = false;
    bool check3 = false;
    bool check4 = false;
    int num4 = 0;
    int num3 = 0;
    int num2 = 0;
    int num22 = 0;
    for (int i = 1; i < 10; i++) {
        if (num_count[i] == 4) {
            check4 = true;
            num4 = i;
        }
        if (num_count[i] == 3) {
            check3 = true;
            num3 = i;
        }
        if (num_count[i] == 2) {
            check2 = true;
            if (num2 == 0) {
                num2 = i;
            }else{
                num22 = i;
                check22 = true;
            }

        }
    }

    if (check4) {
        sum[2] = num4 + 800;
    }
    if(check3 && check2)
        sum[3] = num3 * 10 + num2 + 700;
    if(cl.size() == 1)
        sum[4] = 600 + num[4];
    if(num_continue)
        sum[5] = num[4] + 500;
    if(check3)
        sum[6] = 400 + num3;
    if (check2 && check22) {
        sum[7] = num22 * 10 + num2 + 300;
    }
    if (check2 && !check22) {
        sum[8] = num2 + 200;
    }
    sum[9] = 100 + num[4];

    int ans = 0;

    for (int i = 1; i < 10; i++) {
        ans = max(ans, sum[i]);
    }

    cout << ans;

    return 0;
}