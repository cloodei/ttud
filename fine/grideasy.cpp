#include <iostream>
using namespace std;

int a[64][64];
int m, n;

long long sol(long long i, long long j) {
	if (a[i][j])
		return a[i][j];

	if (i == m && j == n)
		return 1;

	if (j > n)
		return 0;
	if (i > m)
		return 0;

	long long allr = sol(i, j + 1);
	long long alld = sol(i + 1, j);

	return a[i][j] = allr + alld;
}

int main() {
    cout << "Nhap M = ";
    cin >> m;
    cout << "Nhap N = ";
    cin >> n;
    
    cout << "So cach = " << sol(0, 0);

    return 0;
}
