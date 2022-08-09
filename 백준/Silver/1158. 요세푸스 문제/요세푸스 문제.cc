#include <iostream>
#include <deque>

using namespace std;

deque <int> d;
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, k;

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		d.push_back(i);
	}

	cout << "<";
	while (!d.empty()) {

		for (int i = 1; i < k; i++) {

			d.push_back(d.front());
			d.pop_front();
		}



		if (d.size() == 1)
			break;
		else {
			cout << d.front() << ", ";
			d.pop_front();
		}
	}

	cout << d.front() << ">";
	return 0;
}