#include <iostream>
#include <vector>
using namespace std;


int n, m;

int road[101];

bool visited[101];
bool odd_check[101];
int sum = 1;
int t_cnt = 0;
int ans = 1;

//vector<int> v;

//idx는 1부터 시작해야함
void bt(int idx) {


	if (idx >= n || t_cnt >= m) {
		if (ans < sum) {
			ans = sum;
		}
		/*
		for (auto i : v) {
			cout << i << " ";
		}
		*/
		//cout << "합: " << sum << '\n';
		return;
	}


	//0,1이니까 i + 1
	for (int i = idx; i < idx + 2; i++) {


		if (!visited[i]) {
			visited[i] = true;
			if (i == idx) {
				sum += road[i + 1];
				//v.push_back(road[i + 1]);
				t_cnt += 1;
			}
			else {

				if (sum % 2 == 1)
					odd_check[i + 1] = true;
				sum = sum / 2;
				sum += road[i + 1];
				//v.push_back(road[i + 1]);
				t_cnt += 1;

			}

			bt(i + 1);

			if (i == idx) {
				sum -= road[i + 1];
				//v.pop_back();
				t_cnt -= 1;
			}
			else {
				sum -= road[i + 1];
				//v.pop_back();
				if (odd_check[i + 1]) {
					sum = (sum * 2) + 1;

					odd_check[i + 1] = false;
				}
				else {
					sum = sum * 2;
				}
				t_cnt -= 1;
			}

			visited[i] = false;
		}


	}
	






}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);


	cin >> n >> m;


	for (int i = 1; i <= n; i++) {
		cin >> road[i];
	}

	bt(0);


	cout << ans;
	
	return 0;
}