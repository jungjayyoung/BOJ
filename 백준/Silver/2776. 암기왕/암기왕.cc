#include <iostream>
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
	int t;

	cin >> t;

	while (t > 0) {

		cin >> n;
		vector<int> n1(n);			// 노트 1

		for (auto &k : n1) cin >> k; //노트1 정수 입력

		cin >> m;
		vector<pair<int, int>> n2(m);// 노트 2 -- first에 정수를 저장하고 second에 인덱스를 저장한다.
		vector<int> r(m);			// 정답을 출력할 벡터

		
		for (int i = 0; i < m; i++) {		//노트 2 정수 입력
			cin >> n2[i].first;	//정수 저장
			n2[i].second = i;	//인덱스 저장
		}


		// 노트1,노트2 정렬
		sort(n1.begin(), n1.end());
		sort(n2.begin(), n2.end());

		i = 0;
		j = 0;

		while (i < n && j < m) {

			if (n1[i] == n2[j].first) {
				r[n2[j].second] = 1;
				j++;
			}
			else if (n1[i] < n2[j].first) {

				i++;
			}
			else {
				j++;
			}

		}

		//남은 정수 처리
		while (i < n) {		//노트1에 남은 정수가 있다면...

			if (n1[i] == n2[j - 1].first) {
				r[n2[j - 1].second] = 1;
			}

			i++;

		}

		while (j < m) {		//노트2에 남은 정수가 있다면...
			if (n1[i - 1] == n2[j].first) {
				r[n2[j].second] = 1;
			}

			j++;

		}


		//출력
		for (int i = 0; i < m; i++) {
			cout << r[i] << '\n';
		}

		
		t--;
	}

	return 0;
}