#include <iostream>
#include <string>
#include <algorithm>



using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;

    cin >> t;

    while(t--){
        string s;



        int idx = -1;
        char tmpp;
        cin >> s;
        int s_size = s.size();

        // 다 비교해보면서 idx가 가장 큰걸 바꾼다.
        tmpp = s[s_size - 1];
        for (int i = s_size - 2; i >= 0; i--) {
            if (tmpp <= s[i]) {
                tmpp = s[i];
            }else{
                idx = i;
                break;
            }
        }

        if (idx != -1) {
            for (int i = s_size - 1; i >= 0; i--) {
                if (s[idx] < s[i]) {

                    char a = s[idx];
                    s[idx] = s[i];
                    s[i] = a;
                    break;
                }
            }

            reverse(s.begin() + idx + 1, s.end());

            cout << s;


        }else{
            cout << "BIGGEST";
        }
        cout << "\n";

    }


    return 0;
}