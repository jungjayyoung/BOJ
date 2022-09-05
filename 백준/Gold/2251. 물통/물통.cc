#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int a,b,c;
int visited[201][201][201]; // visited[a][b][c] 가 담긴적이 있다.
queue<pair<pair<int,int>,int>> q;
vector<int> v;

void bfs(){


    while(!q.empty()){

        int aa = q.front().first.first;
        int bb = q.front().first.second;
        int cc = q.front().second;

        q.pop();
        if(visited[aa][bb][cc]) continue;
        visited[aa][bb][cc] = 1;

        if(aa == 0){
            v.push_back(cc);
        }


        // a에서 b로
        if(aa + bb > b) q.push({{aa + bb  -b,b},cc});
        else q.push({{0, aa + bb}, cc});

        // a에서 c로
        if(aa + cc > c) q.push({{aa + cc - c, bb}, c});
        else q.push({{0, bb}, aa + cc});
        //b에서 a로
        if(bb + aa > a) q.push({{a, bb + aa - a}, cc});
        else q.push({{bb + aa, 0}, cc});

        //b에서 c로
        if(bb + cc > c) q.push({{aa, bb + cc - c}, c});
        else q.push({{aa, 0}, bb + cc});

        //c에서 a로
        if(aa + cc > a) q.push({{a, bb}, aa + cc - a});
        else q.push({{aa + cc, bb}, 0});
        //c에서 b로
        if(bb + cc > b) q.push({{aa, b}, bb + cc - b});
        else q.push({{aa, bb + cc}, 0});


    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> a >> b >> c;



    q.push({{0, 0}, c});

    bfs();

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }


    return 0;
}