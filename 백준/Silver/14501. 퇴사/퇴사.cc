#include <iostream>
#include <algorithm>
using namespace std;


int t[16] = { 0, };
int p[16] = { 0, };
int max_profit[16] = { 0, };

int max(int a, int b) {

	return a > b ? a : b;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	int next;
	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> t[i] >> p[i];
	}

	for (int i = n; i > 0; i--) {
		next = i + t[i];
		if (next > n + 1) {
			max_profit[i] = max_profit[i + 1];
		}
		else {
			max_profit[i] = max(max_profit[i + 1], max_profit[next] + p[i]);
		}
	}
	

	cout << max_profit[1];
	return 0;
}