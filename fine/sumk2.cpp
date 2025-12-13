#include <iostream>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

long long dp[8192][8192];
long long a[32768];

// k = 11, n = 10, s = 11
// 1  2  3  4  5  6  7  8  9  10

int main() {
	long long k;
	cout << "Nhap k = ";
    cin >> k;
    if (k < 3)
    	cout << "Co tat ca 0 cach phan tich.";

    for (long long n = 1; n < k; ++n)
    	a[n] = n;

    dp[0][0] = 1;
    for (long long n = 1; n < k; ++n) {
    	for (long long s = 0; s <= k; ++s) {
    		dp[s][n] = dp[s][n - 1];
    		if (s >= a[n])
    			dp[s][n] += dp[s - a[n]][n - 1];
    	}
    }

    cout << "Co tat ca " << dp[k][k - 1] << " cach phan tich.";
    return 0;
}
