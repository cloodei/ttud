#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    long long k;
    cin >> k;
    long long f1 = 0, f2 = 1, f3 = 0;

    while (f3 <= k) {
        f1 = f2;
        f2 = f3;
        f3 = f1 + f2;
    }
    cout << f3;

    return 0;
}
