#include <iostream>
#include <cmath>
#include <string>
#include <vector>
typedef __int128 i128;
using namespace std;

long long fibRec(long long n) {
	if (n <= 1LL)
		return n;

	return fibRec(n - 1) + fibRec(n - 2);
}

long long a[65536];
long long fibMemo(long long n) {
	if (a[n])
		return a[n];

	if (n <= 1LL)
		return n;

	return a[n] = fibMemo(n - 1) + fibMemo(n - 2);
}

inline long long fibDyn(long long n) noexcept {
	long long f1 = 0, f2 = 1, f3 = 1;

	for (long long i = 2LL; i < n; ++i) {
		f1 = f2;
		f2 = f3;
		f3 = f1 + f2;
	}

	return f3;
}


inline vector<vector<long long>> mulMat(vector<vector<long long>>& a, vector<vector<long long>>& b) noexcept {
	vector<vector<long long>> res = {{0, 0}, {0, 0}};
	res[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
	res[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
	res[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
	res[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];

	return res;
}

long long fibMat(long long n) noexcept {
	vector<vector<long long>> res = {{1, 0}, {0, 1}};
	vector<vector<long long>> a   = {{1, 1}, {1, 0}};

	while (n) {
		if (n & 1)
			res = mulMat(res, a);

		a = mulMat(a, a);
		n >>= 1;
	}

	return res[1][0];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    long long n;
    cin >> n;

    if (n < 30)
    	cout << fibRec(n) << endl;
    cout << fibMemo(n) << endl << fibDyn(n) << endl << fibMat(n);

    return 0;
}
