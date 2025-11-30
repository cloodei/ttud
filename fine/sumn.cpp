#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <vector>
#include <cstring>
using namespace std;

struct VecHash {
    size_t operator()(const vector<int>& v) const noexcept {
        size_t h = 0;
        for (int x : v)
            h = h * 1315423911u + hash<int>()(x);

        return h;
    }
};

struct VecEq {
    inline bool operator()(const vector<int>& a, const vector<int>& b) const noexcept {
        return a == b;
    }
};


int a[2048];
int negas, cap;
vector<string> fucktxn;
unordered_set<vector<int>, VecHash, VecEq> die;

inline bool check(int n) noexcept {
	int s = 0;
	for (int i = 1; i <= n; ++i)
		s += a[i];

	return s == negas;
}

bool print(int n) noexcept {
	if (check(n)) {
		vector<int> back(n);
		for (int i = 1; i <= n; ++i)
			back[i - 1] = a[i];

		sort(back.begin(), back.end());

		if (die.insert(back).second) {
			string fuck = to_string(negas) + " = ";
			for (int i = 1; i < n; ++i)
				fuck += to_string(a[i]) + '+';

			fuck += to_string(a[n]) + '\n';
			fucktxn.push_back(fuck);
		}
		return true;
	}

	return false;
}

bool out(int n) {
	if (n > cap)
		return print(cap);

	for (int i = negas; i; --i) {
		a[n] = i;
		if (out(n + 1)) {
			if (cap > 5 && n + 3 > cap)
				return true;

			continue;
		}
	}

	return false;
}

inline void sol() noexcept {
	for (int i = 1; i <= negas; ++i) {
		cap = i;
		out(1);
	}
}

int main() {
    cout << "Nhap n = ";
    cin >> negas;

    memset(a, 0x7f, 8192);
    sol();
    sort(fucktxn.begin(), fucktxn.end(), [](string& a, string& b) { return a > b; });

    for (auto& x : fucktxn)
    	cout << x;

    return 0;
}
