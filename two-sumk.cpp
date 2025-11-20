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
    unordered_map<int, int> mp;

    for(int i = 0; i < n; ++i) {
    	int t;
    	cin >> t;
    	mp[t]++;
    }

    int c = 0;
    for (auto& pair : mp)
        if (mp.count(pair.first + k))
            c += pair.second * mp[pair.first + k];

    cout << c;
    return 0;
}
