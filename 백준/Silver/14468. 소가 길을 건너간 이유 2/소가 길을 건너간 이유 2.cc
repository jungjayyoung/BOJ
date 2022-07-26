#include <iostream>
#include <string>



using namespace std;

int pos1[27];
int pos2[27];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < s.size(); i++) {

        if (!pos1[s[i] - 'A']) {
            pos1[s[i] - 'A'] = i + 1;
        }else{
            pos2[s[i] - 'A'] = i + 1;
        }

    }

    for (int j = 0; j < 26; j++) {
        for (int i = 0; i < 26; i++) {

            if (pos1[j] < pos1[i] && pos2[j] > pos1[i] && pos2[i] > pos2[j]) {
                ans++;
            }

        }
    }

    cout << ans;

    return 0;
}