#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
int n;

int arr[5001];
int visited[5001];
vector<ll> v;
vector<int> ans;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        v.push_back(arr[i]);
    }

    sort(v.begin(), v.end());



    ll res = 9987654321;
    // 1. 하나의 액체를 미리 고르고 나머지 두개를 고른다
    for(int i = 0; i<v.size();i++){
        int chosen_idx = i;
        int j = 0;
        int k = v.size() - 1;

        if (j == chosen_idx) {
            j++;
        }
        if (k == chosen_idx) {
            k--;
        }

        bool check = false;


        while (j < k) {
            //cout << v[chosen_idx] << " " << v[j] << " " << v[k] << "\n";

            if (abs(v[chosen_idx] + v[j] + v[k]) < res) {


                res = abs(v[chosen_idx] + v[j] + v[k]);
                ans.clear();
                ans.push_back(v[chosen_idx]);
                ans.push_back(v[j]);
                ans.push_back(v[k]);
            }

            // 1. 세 용액의 합이 0보다 작은 경우
           if (v[chosen_idx] + v[j] + v[k] < 0) {
               j++;
               if (j == chosen_idx) {
                   j++;
               }
            // 2. 세 용액의 합이 0보다 큰 경우
            } else if (v[chosen_idx] + v[j] + v[k] > 0) {
               k--;
               if (k == chosen_idx) {
                   k--;
               }
            // 3. 세 용액의 합이 0인 경우
            }else{
               ans.clear();
               ans.push_back(v[chosen_idx]);
               ans.push_back(v[j]);
               ans.push_back(v[k]);
               check = true;
               break;
            }

        }

        if (check) {
            break;
        }

    }

    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
