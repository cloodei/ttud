#include <iostream>
#include <algorithm>
using namespace std;

int a[16384];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    	cin >> a[i];

    sort(a, a + n, [](int& a, int& b) { return a > b; });
    
    int c = 1, thresh = a[0];
    for (int i = 1; i < n; ++i) {
    	if (thresh) {
    		thresh--;
    		c++;
    	}

    	if (thresh > a[i])
    		thresh = a[i];
    }

    cout << c;
    return 0;
}
