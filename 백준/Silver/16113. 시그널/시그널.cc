#include <iostream>
#include <string>
#include <vector>



using namespace std;

string row[5];


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    string s;

    cin >> n;

    cin >> s;

    for (int i = 0; i < 5; i++) {

        row[i] = s.substr(i * (n / 5), (n / 5));

    }

    int col_size = n / 5;

    for (int i = 0; i < col_size; i++) {
        if (row[0][i] == '#' || row[1][i] == '#' ||
        row[2][i] == '#' || row[3][i] == '#' || row[4][i] == '#'){

            //1,0,6,8 일 경우
            if (row[0][i] == '#' && row[1][i] == '#' && row[2][i] == '#' && row[3][i] == '#'
                && row[4][i] == '#') {
                // 1일 경우
                if((i == col_size - 1) || (row[0][i + 1] == '.' && row[1][i + 1] == '.' && row[2][i + 1] == '.' && row[3][i + 1] == '.'
                                           && row[4][i + 1] == '.')){
                    cout << 1;
                    i++;
                    continue;
                }

                // 0일 경우
                if((row[0][i + 1] == '#' && row[1][i + 1] == '.'
                && row[2][i + 1] == '.' && row[3][i + 1] == '.'
                && row[4][i + 1] == '#' && row[0][i+2] == '#'
                && row[1][i+2] == '#' && row[2][i+2] == '#'
                && row[3][i+2] == '#' && row[4][i+2] == '#')){
                    cout << 0;
                    i = i + 2;
                    continue;
                }

                // 6일 경우
                if((row[0][i + 1] == '#' && row[1][i + 1] == '.'
                && row[2][i + 1] == '#' && row[3][i + 1] == '.'
                && row[4][i + 1] == '#'&& row[0][i + 2] == '#'
                   && row[1][i + 2] == '.' && row[2][i + 2] == '#'
                   && row[3][i + 2] == '#' && row[4][i + 2] == '#')){
                    cout << 6;
                    i = i +2;
                    continue;
                }

                // 8일 경우
                if((row[0][i + 1] == '#' && row[1][i + 1] == '.'
                    && row[2][i + 1] == '#' && row[3][i + 1] == '.'
                    && row[4][i + 1] == '#'&& row[0][i + 2] == '#'
                    && row[1][i + 2] == '#' && row[2][i + 2] == '#'
                    && row[3][i + 2] == '#' && row[4][i + 2] == '#')){
                    cout << 8;
                    i = i +2;
                    continue;
                }

            }

            // 2,3,4,7일 경우
            // 2
            if(row[0][i] == '#' && row[1][i] == '.' && row[2][i] == '#' && row[3][i] == '#' && row[4][i] == '#'){
                cout << 2;
                i = i + 2;
                continue;
            }
            // 3
            if(row[0][i] == '#' && row[1][i] == '.' && row[2][i] == '#' && row[3][i] == '.' && row[4][i] == '#'){
                cout << 3;
                i = i + 2;
                continue;
            }
            //4
            if(row[0][i] == '#' && row[1][i] == '#' && row[2][i] == '#' && row[3][i] == '.' && row[4][i] == '.'){
                cout << 4;
                i = i + 2;
                continue;
            }
            // 7
            if(row[0][i] == '#' && row[1][i] == '.' && row[2][i] == '.' && row[3][i] == '.' && row[4][i] == '.'){
                cout << 7;
                i = i + 2;
                continue;
            }

            // 5
            if(row[0][i + 2] == '#' && row[1][i + 2] == '.' && row[2][i + 2] == '#' && row[3][i + 2] == '#' && row[4][i + 2] == '#'){
                cout << 5;
                i = i + 2;
                continue;
            }

            //9
            if(row[0][i + 2] == '#' && row[1][i + 2] == '#' && row[2][i + 2] == '#' && row[3][i + 2] == '#' && row[4][i + 2] == '#'){
                cout << 9;
                i = i + 2;
                continue;
            }
        }

    }

    return 0;
}