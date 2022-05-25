#include <iostream>

using namespace std;

int childr[27];
int childl[27];

void preorder(int num) {

	cout << char(num + 'A');
	if (childl[num] != '.' - 'A')
		preorder(childl[num]);
	if (childr[num] != '.' - 'A')
		preorder(childr[num]);

}

void inorder(int num) {

	if (childl[num] != '.' -'A')
		inorder(childl[num]);
	cout << char(num + 'A');
	if (childr[num] != '.' - 'A')
		inorder(childr[num]);
}

void postorder(int num) {

	if (childl[num] != '.' - 'A')
		postorder(childl[num]);
	if (childr[num] != '.' - 'A')
		postorder(childr[num]);
	cout << char(num + 'A');

}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	char a, b, c;

	cin >> n;

	for (int i = 0; i < n; i++) {

		cin >> a >> b >> c;
		
		
		childl[a - 'A'] = b - 'A';
		
		childr[a - 'A'] = c - 'A';
	
	}

	preorder(0); cout << '\n';
	inorder(0); cout << '\n';
	postorder(0); cout << '\n';

	return 0;
}