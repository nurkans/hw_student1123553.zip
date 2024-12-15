// question4.cpp
// Name: [Nurbyergyen]
// Student ID: [1123553]
// Date of Submission: [2024.12.12]

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int primsMST(int V, const vector<vector<pair<int, int>>>& adj) {
    vector<int> visited(V, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0}); // {weight, node}
    int mstWeight = 0;

    while (!pq.empty()) {
        auto [weight, node] = pq.top();
        pq.pop();

        if (visited[node]) continue;
        visited[node] = 1;
        mstWeight += weight;

        for (auto [neighbor, edgeWeight] : adj[node]) {
            if (!visited[neighbor]) {
                pq.push({edgeWeight, neighbor});
            }
        }
    }
    return mstWeight;
}

int main() {
    int V = 3;
    vector<vector<pair<int, int>>> adj(V);
    adj[0] = {{1, 5}, {2, 1}};
    adj[1] = {{0, 5}, {2, 3}};
    adj[2] = {{0, 1}, {1, 3}};

    cout << "MST Weight: " << primsMST(V, adj) << endl;

    return 0;
}
