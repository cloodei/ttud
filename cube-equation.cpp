#include <iostream>
#include <cmath>
#include <string>
typedef __int128 i128;
using namespace std;

double a, b, c, d;

inline double fx(double x) noexcept {
	return a * a * a * x + b * b * x + c * x + d;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> a >> b >> c >> d;

    double l = -1000000.0, r = 1000000.0;

    while (l < r) {
    	double left = fx(l), right = fx(r), m = (l + r) / 2.0, mid = fx(m);
    	if (mid <= 0.00001 && mid >= -0.00001) {
    		cout << m;
    		return 0;
    	}
    	if (mid < -0.00001)
    		l = mid;
    	else
    		r = mid;
    }

    cout << l;
    return 0;
}
