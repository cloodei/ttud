#include <iostream>
#include <vector>
using namespace std;

int a[128];
int n, m;

void print() {
	int s = 0;
	for (int i = 1; i <= m; ++i)
		s += a[i];

	if (s == n) {
		cout << n << " = ";
		for (int i = 1; i < m; ++i)
			cout << a[i] << '+';

		cout << a[m] << '\n';
	}
}

void sol(int x) {
	if (x > m) {
		print();
		return;
	}

	for (int i = 1; i <= n; ++i) {
		a[x] = i;
		sol(x + 1);
	}
}

int main() {
    cout << "Nhap n = ";
    cin >> n;
    cout << "Nhap m = ";
    cin >> m;

    sol(1);

    return 0;
}
