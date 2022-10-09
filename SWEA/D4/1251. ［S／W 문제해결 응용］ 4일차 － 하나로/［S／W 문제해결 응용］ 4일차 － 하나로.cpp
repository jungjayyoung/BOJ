#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

int T,n;
ll xx[1001];
ll yy[1001];
int parent[1001];
int tree_level[1001];
double e;
double ans = 0;

vector<pair<pair<int,int>,double>> v;

bool cmp(pair<pair<int, int>, double> a, pair<pair<int, int>, double> b){

    return a.second < b.second;

}

int find_parent(int u){

    if (parent[u] == u) {
        return u;
    }

    return parent[u] = find_parent(parent[u]);

}


void join_node(int u, int v, double cost){

    u = find_parent(u);
    v = find_parent(v);

    if (u == v) {
        return;
    }

    if (tree_level[u] <= tree_level[v]) {
        tree_level[u] += tree_level[v];
        parent[u] = v;
    }else{
        tree_level[v] += tree_level[u];
        parent[v] = u;
    }

    ans += cost;
    return;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;

    for (int t = 1; t <= T; t++) {

        ans = 0;
        v.clear();
        cin >> n;

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < n; i++) {
            tree_level[i] = 1;
        }



        for (int i = 0; i < n; i++) {
            ll a;
            cin >> a;
            xx[i] = a;
        }

        for (int i = 0; i < n; i++) {
            ll a;
            cin >> a;
            yy[i] = a;
        }

        cin >> e;


        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {
                double cost = e * (pow(xx[i] - xx[j], 2) + pow(yy[i] - yy[j], 2));
                v.push_back({{i, j}, cost});
            }
        }

        sort(v.begin(),v.end(),cmp);

        for (int i = 0; i < v.size(); i++) {

            int a = v[i].first.first;
            int b = v[i].first.second;
            double c = v[i].second;

            join_node(a, b, c);
        }

        cout << fixed;
        cout.precision(0);

        cout << "#" << t << " " << ans << "\n";

    }


    return 0;
}