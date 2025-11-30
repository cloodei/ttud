#include <iostream>
using namespace std;

long long a[16777216];
long long n;

long long sol(long long k) {
	if (a[k])
		return a[k];

	if (k == n)
		return 1;

	if (k > n)
		return 0;

	long long all1 = sol(k + 1);
	long long all2 = sol(k + 2) * 2;

	return a[k] = all1 + all2;
}

int main() {
    cout << "N = ";
    cin >> n;
    cout << "So phuong an = " << sol(0);

    return 0;
}
