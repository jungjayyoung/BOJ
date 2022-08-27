#include <iostream>
#include <vector>

using namespace std;



int n,m;
int parent[51];
int tree_level[51];
vector<int> party[51];
vector<int> t;
bool c[51];

int find_parent(int u){
    if (parent[u] == u) {
        return u;
    }

    return parent[u] = find_parent(parent[u]);
}

void join_node(int u,int v){

    int uu = find_parent(u);
    int vv = find_parent(v);

    if(uu == vv){
        return;
    }
    if(tree_level[uu] > tree_level[vv]){
        int tmp = uu; uu = vv; vv = tmp;
    }

    parent[uu] = vv;
    if (tree_level[uu] == tree_level[vv]) {
        tree_level[vv]++;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n >> m; // 사람 수, 파티 수


    for (int i = 0; i <= n; i++) {
        parent[i] = i;
        tree_level[i] = 1;
    }

    int truth;

    cin >> truth;

    for (int i = 0; i < truth; i++) {
        int p;
        cin >> p;
        t.push_back(p);
        join_node(p, 0); // 진실을 아는 친구들의 부모는 0 이된다.
        // 또한 이들의 tree_level 은 1보다 높다.

    }

    for(int i = 0; i < m; i++){
        int num;
        cin >> num;

        //  파티 하나에 들어가는 사람들의 모음을 벡터에 넣는다.
        for (int j = 0; j < num; j++) {
            int a;
            cin >> a;
            party[i].push_back(a);
        }

    }

    // 입력 끝

    //파티에 들어간 사람들끼리 집합을 만든다.
    for (int i = 0; i < m; i++) {
        for (int j = 1; j < party[i].size(); j++) {
            join_node(party[i][j - 1], party[i][j]);
        }
    }


    for (int i = 0; i < t.size(); i++) {
        join_node(t[i], 0);
    }
    // 이제 다시 파티에 있는 사람들 중에서 진실을 아는 사람들이 있으면 묶어준다.

    // 아니 굳이?
    // 그냥 안묶고 여기서 답 증가시키면 된다!
    int ans = 0;
    for (int i = 0; i < m; i++) {

        for (int j: party[i]) {

            if(find_parent(j) == find_parent(0)){

                c[i] = true;
                for (int k: party[i]) {
                    join_node(k, 0);

                }
                break;
            }
        }
    }

    for (int i = 0; i < m; i++) {

        for (int j: party[i]) {

            if(find_parent(j) == find_parent(0)){

                c[i] = true;
                for (int k: party[i]) {
                    join_node(k, 0);

                }
                break;
            }
        }
    }

  
    for (int i = 0; i < m; i++) {
        if (!c[i]) {
            ans++;
        }
    }
    cout << ans;



    return 0;
}