#include <iostream>

using namespace std;

int main()
{
	int num[9];
	int i,j;
	int a, b;
	int sum = 0;
	for (i = 0; i < 9; ++i)
	{

		cin >> num[i];
		sum += num[i];
	}
	for (i = 0; i < 8; ++i)
	{
		for (j = i + 1; j < 9; ++j)
		{
			if (num[i] + num[j] == sum - 100)
			{
				a = i;
				b = j;

			}

		}



	}

	for (i = 0; i < 9; ++i)
	{
		if(i!=a&&i!=b)
		cout << num[i] << "\n";


	 }
	
	return 0;
}