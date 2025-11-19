#include <iostream>
#include <cmath>
#include <string>
#include <unordered_map>
typedef __int128 i128;
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    // int a[100];
    unordered_map<int, int> mp;

    for(int i = 0; i < n; ++i) {
    	int t;
    	cin >> t;
    	int sub = abs(t - k);
    	mp[t]++;
    }



    return 0;
}
