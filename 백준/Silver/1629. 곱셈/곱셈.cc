#include <iostream>

using namespace std;

typedef long long ll;


ll a, b, c;

ll pow(ll a, ll b) {

	
	if (b == 0)
		return 1;

	ll r = pow(a, b / 2);

	if (b % 2 == 0) {
		return r * r % c;
	}
	else
		return a * (r * r % c) % c;


}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	

	cin >> a >> b >> c;


	cout << pow(a, b);



	return 0;
}