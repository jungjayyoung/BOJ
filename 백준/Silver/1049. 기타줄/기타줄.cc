#include <iostream>

#include <vector>
#include <algorithm>


using namespace std;

int n,m;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    int ans =10000000;
    int min_one =100000;
    int min_pack = 100000;
    int total = 0;

    // 7개 이상일 경우 생각
    int select;
    int nn;

    if (n == 6) {
        nn = 6;
    }else {
        nn = n % 6;
    }
    for(int i = 0; i < m; i++){
        int pack, one;

        cin >> pack >> one;

        min_one = min(min_one,one);
        min_pack = min(min_pack,pack);


        if(pack > one * nn){
            select = one * nn;
        }else{
            select = pack;
        }

        ans = min(ans,select);
    }

    //ans는 6개 이하일때 최소 가격

    total += ans;

    int r = n - nn; // r은 6의 배수다. 이 때는 min_one과 min_pack 중 최소 값으로 몫 만큼 곱한 값을 total에 더한다.
    int mm = min(min_one * 6, min_pack);

    if (r > 0) {
        total += (r /6) * mm;
    }

    cout << total;


    return 0;
}



