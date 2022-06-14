#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;

    cin >> t;
    cin.ignore();

    while (t--) {

        vector<string> v;
        vector<string> ans;

        string str;
        getline(cin, str);
        stringstream ss(str);
        string tmp;

        while (ss>>tmp) {
            ans.push_back(tmp);
        }

        while (1) {

            string sound;

            getline(cin, sound);

            if(sound == "what does the fox say?"){
                break;
            }
            bool check = false;
            int cnt = 0;
            string animals = "";

            for (int i = 0; i < sound.size(); i++) {

                if(sound[i] == ' '){
                    cnt++;

                    if (cnt == 2) {
                        check = true;
                        continue;
                    }
                }

                if (check) {
                    animals += sound[i];
                }

            }

            v.push_back(animals);

        }


        for (int i = 0; i < ans.size(); i++) {

            bool not_fox = false;
            for (int j = 0; j < v.size(); j++) {

                if (ans[i] == v[j]) {
                    not_fox = true;
                    break;
                }

            }

            if (!not_fox) {
                cout << ans[i] << " ";
            }

        }


        cout << "\n";


    }



    return 0;
}