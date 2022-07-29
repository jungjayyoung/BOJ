#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> v;

int visited[26];
int visited2[26];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {

        string s;
        cin >> s;
        v.push_back(s);
    }

    int str_size = v[0].size();
    int ans = 0;
    for (int i = 0; i < v.size() - 1; i++) {

        string cur_str = v[i];

        for (int j = i + 1; j < v.size(); j++) {

            fill(visited, visited + 26, -1);
            fill(visited2, visited2 + 26, 0);
            string next_str = v[j];
            bool check = false;
            for (int k = 0; k < str_size; k++) {

                if (visited[cur_str[k] - 'a'] == -1) {
                    if (visited2[next_str[k] - 'a']) {
                        check = true;
                        break;
                    }
                    visited[cur_str[k] - 'a'] = next_str[k] - 'a';
                    visited2[next_str[k] - 'a'] = 1;

                }else if(visited[cur_str[k] - 'a'] != -1){
                    if (visited[cur_str[k] - 'a'] != next_str[k] - 'a' ) {
                        check = true;
                        break;
                    }
                }

            }
            if (!check) {
                ans++;
            }
        }
    }

    cout << ans;
    return 0;
}