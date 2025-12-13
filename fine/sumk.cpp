#include <iostream>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

map<pair<long long, long long>, long long> marp;
long long a[1024];

long long sol(long long s, long long n) {
	if  (s == 0)
		return 1;
	if  (n == 0)
		return 0;
	if  (marp.count({ s, n }))
		return marp[{ s, n }];

	return marp[{ s, n }] = sol(s - a[n], n - 1) + sol(s, n - 1);
}

int main() {
	long long k;
	cout << "Nhap k = ";
    cin >> k;

    for (long long i = 1; i < k; ++i)
    	a[i] = i;

    cout << "Co tat ca " << sol(k, k - 1) << " cach phan tich.";
    return 0;
}
