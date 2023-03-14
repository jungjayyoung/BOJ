#include <iostream>
#include <string>


using namespace std;



string str;
int visited[2501];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> str;

    if (str.size() % 5 != 0) {
        cout << -1;
        return 0;
    }

    int ans = 0;

    for (int j = 0; j < str.size(); j++) {

        char pre = 'k';
        if (str[j] == 'q' && visited[j] == 0) {
            for (int i = j; i < str.size(); i++) {

                if (visited[i] == 0 && str[i] == 'q' && pre == 'k') {

                    if(pre == 'k') {
                        visited[i] = 1;
                        pre = 'q';
                    }

                }
                if (visited[i] == 0 && str[i] == 'u' && pre == 'q') {
                    if (pre == 'q') {
                        visited[i] = 1;
                        pre = 'u';
                    }
                }
                if (visited[i] == 0 && str[i] == 'a' && pre == 'u') {
                    if (pre == 'u') {
                        visited[i] = 1;
                        pre = 'a';
                    }
                }
                if (visited[i] == 0 && str[i] == 'c'&& pre == 'a') {
                    if (pre == 'a') {
                        visited[i] = 1;
                        pre = 'c';
                    }
                }
                if (visited[i] == 0 && str[i] == 'k' && pre == 'c') {
                    if (pre == 'c') {
                        visited[i] = 1;
                        pre = 'k';
                    }
                }
            }

            if (pre == 'k') {
                ans++;
            }
        }

    }

    for (int i = 0; i < str.size(); i++) {
        if (visited[i] == 0) {
            cout << -1;
            return 0;
        }
    }

    if (ans == 0) {
        cout << -1;
    }else
        cout << ans;



    return 0;
}