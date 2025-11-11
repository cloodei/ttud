#include <iostream>
#include <cmath>
#include <string>
typedef __int128 i128;
using namespace std;

constexpr long long MOD = 1e9;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    long long a, b;
    cin >> a >> b;

    long long res = 1, na = a, nb = b;
    while (nb) {
    	if (nb & 1)
    		res = res * na % MOD;

    	na = na * na % MOD;
    	nb >>= 1;
    }

    cout << res;

    return 0;
}
