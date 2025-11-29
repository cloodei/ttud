#include <iostream>
#include <sort/cntsorts>
typedef __int128 i128;
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;

    int* a = new int[n];
    for (int i = 0; i < n; ++i)
    	cin >> a[i];

    radixSort(a, n);

    int m = a[1] - a[0];
    for (int i = 2; i < n; ++i)
		m = min(m, a[i] - a[i - 1]);

	int c = 0;
	for (int i = 1; i < n; ++i)
		if (a[i] - a[i - 1] == m)
			c++;

	cout << c;
    return 0;
}
