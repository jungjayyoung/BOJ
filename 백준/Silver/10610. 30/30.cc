#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;



bool zero;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	string str;
	int sum = 0;
	cin >> str;

	

	
	for (int i = 0; i < str.size(); i++) {
		sum += (str[i] - '0');
		if (str[i] -'0' == 0)
			zero = true;
	}
	if (sum % 3 != 0 || !zero) {
		cout << -1;
		return 0;
	}

	sort(str.begin(), str.end(), greater<int>());
	cout << str;




	return 0;
}