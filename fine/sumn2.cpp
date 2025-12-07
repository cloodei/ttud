#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdint>
using namespace std;

int a[16384], b[16384];
int n, now;

int some(int x) {
	int s = 0;
	for (int i = 1; i <= x; ++i)
		s += a[i];

	return s;
}

void print(int x) {
	cout << n << " = " << a[1];
	for (int i = 2; i < x; ++i)
		cout << '+' << a[i];

	if (a[x])
		cout << '+' << a[x];
	cout << '\n';
}

void run(int x) {
	int s;
	if (x > b[now]) {
		s = some(x - 1);
		if (s == n)
			print(x - 1);

		return;
	}

	s = some(x - 1);
	if (s > n)
		return;

	if (s == n) {
		print(x - 1);
		return;
	}

	for (int i = a[x - 1]; i; --i) {
		a[x] = i;
		run(x + 1);
	}
}

void go() {
	cout << n << " = " << n << '\n';
	for (int i = n - 1; i; --i) {
		a[1] = now = i;
		run(2);
		memset(a, 0, 16384 * 4);
	}
}

int main() {
	cout << "Nhap n = ";
	cin >> n;
	for (int i = 1; i <= n; ++i)
		b[i] = n - i + 1;
	
	go();
}
