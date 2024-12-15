// question2.cpp
// Name: [Nurbyergyen]
// Student ID: [1123553]
// Date of Submission: [2024.12.12]

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfsTraversal(const vector<vector<int>>& adj) {
    vector<int> visited(adj.size(), 0), result;
    queue<int> q;
    q.push(0);
    visited[0] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                q.push(neighbor);
            }
        }
    }
    return result;
}

int main() {
    vector<vector<int>> adj = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
    vector<int> bfs = bfsTraversal(adj);

    for (int node : bfs) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
