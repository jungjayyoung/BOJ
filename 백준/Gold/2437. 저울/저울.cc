#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
using namespace std;


vector<ll> v;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);


	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		ll a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	ll sum = 0;

	for (int i = 0; i < n; i++) {

		if (sum + 2 <= v[i]) break;
		sum += v[i];
	
	}

	cout << sum + 1;
	return 0;
}