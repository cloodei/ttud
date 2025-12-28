#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<vector<int>> matrix(2048, vector<int>(2048, 0));
int dist[16384];
int v[16384];
int maxValue[16384];

int main() {
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++)
        cin >> v[i];

    cin >> m;
    for (int i = 0; i < m; i++) {
        int p, q, u;
        cin >> p >> q >> u;
        matrix[p][q] = u;
        matrix[q][p] = u;
    }

    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        maxValue[i] = 0;
    }

    dist[1] = 0;
    pq.push({ 0, 1 });
    maxValue[1] = v[1];

    while (!pq.empty()) {
    	int distance = pq.top().first;
    	int u = pq.top().second;
    	pq.pop();

    	for (int i = 1; i <= n; i++) {
    		if (matrix[u][i] != 0) {
    			if (dist[u] + matrix[u][i] < dist[i]) {
    				dist[i] = dist[u] + matrix[u][i];
    				maxValue[i] = maxValue[u] + v[i];
    				pq.push({ dist[i], i });
				}
				else if (dist[u] + matrix[u][i] == dist[i] && maxValue[u] + v[i] > maxValue[i]) {
					maxValue[i] = maxValue[u] + v[i];
				}
			}
		}
	}

	cout << maxValue[n];
	return 0;
}
