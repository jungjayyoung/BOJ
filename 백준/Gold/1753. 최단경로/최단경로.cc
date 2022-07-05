//다익스트라 알고리즘 문제
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> q; // pair<현재 거리, 정점의 번호> 저장
												//greater를 쓴 이유는 항상 현재거리가 최소인 정점을 가져와야하므로

ll n, e, k, V, dist[20001];//처음 정점부터에서의 거리를 저장할 dist라는 배열을 만든다.
const ll inf = 1e18; // 10^18

vector<pair<ll, ll>> v[20001];//정점이 어디와 연결이 되어있는지 간선 정보를 인접리스트로 벡터에 저장
							//v[u] {v,w} 라는 정보를 저장

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> e;
	cin >> k;
	V = n;
	while (e--) {
		ll a, b, c;
		cin >> a >> b >> c;

		v[a].push_back({ b,c });

	}

	fill(dist, dist + V + 1, inf);
	dist[k] = 0;

	q.push({ 0,k });

	while (q.size()) {

		auto cur = q.top();
		q.pop();

		if (dist[cur.second] < cur.first) continue;//지금까지의 최소거리가 현재거리보다 작다면 볼 필요 없다.
													// 이 코드가 있어서 방문체크를 할 필요가 없다.
		for (auto nxt : v[cur.second]) {
			if (dist[nxt.first] <= cur.first + nxt.second) continue;
			dist[nxt.first] = cur.first + nxt.second;
			q.push({ dist[nxt.first], nxt.first });

		}

	}

	for (int i = 1; i <= V; i++) {

		if (dist[i] == inf)
			cout << "INF" << '\n';
		else
			cout << dist[i] << '\n';

	}

	return 0;
}