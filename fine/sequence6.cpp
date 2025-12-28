#include <iostream>
#include <cmath>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
    long long n, count = 0;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a + 0, a + n);

    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            long long diff = a[j] - a[i];
            int sot3 = a[i] + 2*diff;
            int sot4 = a[i] + 3*diff;
            int sot5 = a[i] + 4*diff;
            if (binary_search(a + j, a + n, sot3) && binary_search(a + j, a + n, sot4) && binary_search(a + j, a + n, sot5)) {
                count++;
            }
        }
    }
    cout << count;
}
