#include <iostream>
#include <algorithm>


using namespace std;
int max_col[3];
int min_col[3];
int n;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;



    //1. 첫번째 줄은 max_pre 와 min_pre 전부 같은 값을 집어넣는다.
    cin >> max_col[0] >> max_col[1] >> max_col[2];
    min_col[0] = max_col[0];
    min_col[1] = max_col[1];
    min_col[2] = max_col[2];

    for (int i = 1; i < n; i++) {
        int a, b, c;
        int pre_min1, pre_min2, pre_min3, pre_max1, pre_max2, pre_max3;
        cin >> a >> b >> c;
        pre_min1 = min_col[0];
        pre_min2 = min_col[1];
        pre_min3 = min_col[2];

        pre_max1 = max_col[0];
        pre_max2 = max_col[1];
        pre_max3 = max_col[2];


        min_col[0] = a + min(pre_min1, pre_min2);
        min_col[1] = b + min(min(pre_min1, pre_min2), pre_min3);
        min_col[2] = c + min(pre_min2, pre_min3);

        max_col[0] = a + max(pre_max1, pre_max2);
        max_col[1] = b + max(max(pre_max1, pre_max2), pre_max3);
        max_col[2] = c + max(pre_max2, pre_max3);
    }


    int max_score, min_score;

    max_score = max(max(max_col[0], max_col[1]), max_col[2]);
    min_score = min(min(min_col[0], min_col[1]), min_col[2]);

    cout << max_score << " " << min_score;

    return 0;
}