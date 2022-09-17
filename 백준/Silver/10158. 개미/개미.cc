#include <iostream>


using namespace std;



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int w, h, a, b, t;

    cin >> w >> h >> a >> b >> t;

    int tx = t % (2 * w);
    int ty = t % (2 * h);

    a = tx + a;
    b = ty + b;


    if(a > w) a = 2 * w - a;
    if(b > h) b = 2 * h - b;
    if(a < 0) a = -a;
    if(b < 0) b = -b;

    cout << a << " " << b;








    return 0;
}