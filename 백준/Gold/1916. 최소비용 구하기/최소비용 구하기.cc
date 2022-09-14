#include <iostream>
#include <queue>
#include <vector>
using namespace std;

using ll = long long;

const ll inf = 1e18;

priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;	// 현재까지의 비용, 정점의 번호

vector<pair<ll, ll>> v[1001]; // v[u]{v,w} u와 v는 w의 가중치로 연결됨

ll n, m; //도시 갯수,버스 갯수 
ll dist[1002];
ll s, e; //시작점,도착점
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;

	while (m--) {

		ll a, b, c;// 출발도시번호, 도착점 도시번호, 버스 비용

		cin >> a >> b >> c;

		v[a].push_back({ b,c });
	}

	cin >> s >> e;

	fill(dist, dist + n + 1, inf);
	pq.push({ 0,s });
	dist[s] = 0;

	while (pq.size()) {

		auto cur = pq.top();
		pq.pop();

		if (dist[cur.second] < cur.first) continue;

		for (auto nxt : v[cur.second]) {
			if (dist[nxt.first] <= nxt.second + cur.first) continue;
			dist[nxt.first] = nxt.second + cur.first;
			pq.push({ dist[nxt.first],nxt.first });

		}

	}
	
	cout << dist[e];

	return 0;
}