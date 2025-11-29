#include <iostream>
#include <algorithm>
using namespace std;

long long a[256];

long long bins(long long l, long long r, long long x) noexcept {
	while (l <= r) {
		long long m = (l + r) >> 1;
		if (a[m] == x)
			return m;

		if (a[m] < x)
			l = m + 1;
		else
			r = m - 1;
	}

	return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    long long n;
    cin >> n;

    for (long long i = 0; i < n; ++i)
    	cin >> a[i];

    sort(a, a + n);

    long long c = 0;
    for (long long i = 0; i < n - 4; ++i) {
    	for(long long j = i + 1; j < n - 3; ++j) {
    		long long d = a[j] - a[i];
    		long long find3 = a[j] + d, find4 = find3 + d, find5 = find4 + d;

    		long long id3 = bins(j + 1, n - 1, find3);
    		if (id3) {
    			long long id4 = bins(id3 + 1, n - 1, find4);
    			if (id4) {
    				long long id5 = bins(id4 + 1, n - 1, find5);
    				if (id5)
    					++c;
    			}
    		}
    	}
    }

    cout << c;
    return 0;
}
