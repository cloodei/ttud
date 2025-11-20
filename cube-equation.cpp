#include <iostream>
#include <cmath>
#include <string>
typedef __int128 i128;
using namespace std;

// 1 -14588 31196079 -18054298332

constexpr double EL = 0.00001;
double a, b, c, d;

inline double fx(double x) noexcept {
	return a * 1.0 * x * x * x + b * x * x + c * x + d;
}

int main() {
    cin >> a >> b >> c >> d;
    double l = -1000000.0, r = 1000000.0;

    while (l < r) {
    	double m = (l + r) / 2.0;
        double mid = fx(m);
    	if (mid <= EL && mid >= -EL) {
    		cout << m;
    		return 0;
    	}
    	if (mid < 0)
    		l = m;
    	else
    		r = m;
    }

    cout << l;
    return 0;
}
