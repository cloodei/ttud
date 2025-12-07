#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

long long n, m;

int main() {
    cout << "Nhap m = ";
    cin >> m;
    vector<long long> a(m + 1);
    for (long long i = 0; i < m; ++i) {
    	cout << "a[" << i + 1 << "] = ";
    	cin >> a[i];
    }

    cout << "Nhap n = ";
    cin >> n;
    vector<long long> b(n + 1);
    for (long long i = 0; i < n; ++i) {
    	cout << "b[" << i + 1 << "] = ";
    	cin >> b[i];
    }

    vector<vector<long long>> dp(m + 2);
    for (int i = 0; i <= m + 1; ++i) {
    	dp[i].reserve(n + 2);
    	dp[i].resize(n + 2, 0);
    }

    for (int i = 1; i <= m; ++i)
    	for (int j = 1; j <= n; ++j)
    		if (a[i - 1] == b[j - 1])
    			dp[i][j] = dp[i - 1][j - 1] + a[i - 1];
    		else
    			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    cout << "Day con co tong lon nhat = " << dp[m][n];
    return 0;
}
