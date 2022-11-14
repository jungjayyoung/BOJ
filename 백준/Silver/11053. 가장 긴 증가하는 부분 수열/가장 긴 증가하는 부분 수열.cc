#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1000];
int dp[1000];
int ans = 1;
//int len(int arr[])
//{
//	int inc = 1;
//	int pre;
//	pre = arr[0];
//	for (int i = 1; i < n; i++)
//	{
//		if (pre < arr[i])
//		{
//			inc++;
//		}
//		pre = arr[i];
//	}
//	return inc;
//}


int main()
{

	
	fill_n(dp, 1000, 1);
	
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {

		int inc = 1;
		int pre = arr[i];

		for (int j = 0; j < i; j++) {

			if (pre > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}

		}

		ans = max(ans, dp[i]);
	}

	cout << ans;
	return 0;
}