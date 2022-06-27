#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 1234567

int a[MAX];
int tmp[MAX];


long long cnt;
void merge_sort(int start, int mid, int end) { // [start, mid) [mid, end) 
	int p1, p2, index = 0;
	p1 = start;
	p2 = mid;
	while (p1 < mid && p2 < end) {
		if (a[p1] < a[p2]) {
			tmp[index++] = a[p1++];
		}
		else if (a[p1] > a[p2]) {
			cnt += mid - p1;
			tmp[index++] = a[p2++];
		}
		else {
			tmp[index++] = a[p2++];
		}

	}

	while (p1 < mid)
	{
		tmp[index++] = a[p1++];
	}
	while (p2 < end) {
		tmp[index++] = a[p2++];
	}
	for (int i = 0; i < end - start; ++i) {
		a[start + i] = tmp[i];
	}
}


void merge(int s, int e) {


	int m = (s + e) / 2;

	if (s < m) {
		merge(s, m);
		merge(m, e);
		merge_sort(s, m, e);
	}
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cnt = 0;
	int n;

	cin >> n;
	
	for (int i = 0; i < n; i++) cin >> a[i];

	merge(0, n);

	
	cout << cnt;
	return 0;
}