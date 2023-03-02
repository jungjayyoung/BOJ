#include <iostream>
#include <string>

using namespace std;

int visited[26];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();


    string str;

    int t;
    int cnt = 1;
    cin >> t;

    cin.ignore();

    while (t--) {
        getline(cin, str);
        fill(visited, visited + 26, 0);

        for (int i = 0; i < str.size(); i++) {
            if (str[i] >= 'a' && str[i] <= 'z') {
                visited[str[i] - 'a']++;
            }
            if (str[i] >= 'A' && str[i] <= 'Z') {
                visited[str[i] - 'A']++;
            }
        }

        bool check1 = true;
        bool check2 = true;
        bool check3 = true;

        for (int i = 0; i < 26; i++) {
            if (visited[i] == 0) {
                check1 = false;
                check2 = false;
                check3 = false;
            } else if (visited[i] == 1) {
                check2 = false;
                check3 = false;
            } else if (visited[i] == 2) {
                check3 = false;
            }
        }

        if (check3) {
            cout << "Case " << cnt <<": Triple pangram!!!" << "\n";
        } else if (check2) {
            cout << "Case " << cnt <<": Double pangram!!" << "\n";
        } else if (check1) {
            cout << "Case " << cnt <<": Pangram!" << "\n";
        } else {
            cout << "Case " << cnt <<": Not a pangram" << "\n";
        }
        cnt++;
    }

    return 0;
}