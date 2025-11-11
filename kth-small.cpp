#include <iostream>
#include <cmath>
#include <string>
typedef __int128 i128;
using namespace std;

constexpr int SIZE = 32;
int n, k;

int partition(int a[], int left, int right) {
	int pivot = a[right];
	int i = left;

	for (int j = left; j < right; ++j)
		if (a[j] <= pivot)
			swap(a[i++], a[j]);

	swap(a[i], a[right]);
	return i;
}

int quickSelect(int a[], int left, int right) {
	if (left <= right) {
		int i = partition(a, left, right);
		if (i == k)
			return a[k];
		if (i > k)
			return quickSelect(a, left, i - 1);

		return quickSelect(a, i + 1, right);
	}
	return -1;
}

int K(int a[]) {
	int arr[SIZE];
	memcpy(arr, a, SIZE * 4);
	return quickSelect(arr, 0, n - 1);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> k;
    int a[SIZE];
    k--;
    for (int i = 0; i < n; ++i)
    	cin >> a[i];

    cout << K(a);

    return 0;
}
