#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	int i, j;
	cin >> n >> m;

	vector<string> d(n);
	vector<string> b(m);
	vector<string> r;
	for (auto &k : d) {
		cin >> k;
	}


	for (auto &k : b) {
		cin >> k;
	}

	sort(d.begin(), d.end());
	sort(b.begin(), b.end());

	i = 0;
	j = 0;

	while (i < n && j < m) {

		if (d[i].compare(b[j]) == 0) {
			r.push_back(d[i]);
			i++;
			j++;

		}
		else if (d[i].compare(b[j]) < 0) {
			i++;

		}
		else {
			j++;
		}


	}

	cout << r.size() << '\n';
	for (auto &k : r) {
		cout << k << '\n';
	}

	return 0;
}