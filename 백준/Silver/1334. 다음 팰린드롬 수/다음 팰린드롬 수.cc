#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

string BigintAdd(string s1, string s2){


    int sum = 0;
    int idx = 0;
    string ans = "";

    while(!s1.empty() || !s2.empty() || sum){
        int num1 = 0;
        int num2 = 0;
        if(!s1.empty()){
            num1 = s1.back() - '0';
            s1.pop_back();
        }

        if (!s2.empty()) {
            num2 = s2.back() - '0';
            s2.pop_back();
        }

        sum = sum + num1 + num2;

        ans = ans + to_string(sum % 10);
        sum /= 10;

    }

    reverse(ans.begin(), ans.end());

    return ans;

}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    string s;
    cin >> s;

    int n = s.size();
    string ans;
    string prefix = s.substr(0, n / 2);
    string suffix = prefix;
    reverse(suffix.begin(), suffix.end());
    string mid;
    if (n % 2 != 0) {
        mid = s[n / 2];
    }

    ans = prefix + mid + suffix;


    while (ans <= s) {

        bool nine_check = true;

        for (int i = 0; i < ans.size(); i++) {
            if(ans[i] != '9') {
                nine_check = false;
                break;
            }
        }
        if (nine_check) {
            string tmp;
            tmp = "1";
            for (int i = 0; i < ans.size() - 1; i++) {
                tmp = tmp + "0";
            }
            ans = tmp + "1";
            break;
        }

        if (!mid.empty()) {
            if (mid == "9") {
                mid = "0";
                prefix = BigintAdd(prefix, "1");
                suffix = prefix;
                reverse(suffix.begin(), suffix.end());
                ans = prefix + mid + suffix;
            }else{
                mid = to_string(stoi(mid) + 1);
                ans = prefix + mid +suffix;
            }

        }else{
            prefix = BigintAdd(prefix, "1");
            suffix = prefix;
            reverse(suffix.begin(), suffix.end());
            ans = prefix + suffix;
        }

    }


    cout << ans;



    return 0;
}