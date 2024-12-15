// question3.cpp
// Name: [Nurbyergyen]
// Student ID: [1123553]
// Date of Submission: [2024.12.12]

#include <iostream>
#include <vector>
using namespace std;

void dfsHelper(int node, const vector<vector<int>>& adj, vector<int>& visited, vector<int>& result) {
    visited[node] = 1;
    result.push_back(node);

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfsHelper(neighbor, adj, visited, result);
        }
    }
}

vector<int> dfsTraversal(const vector<vector<int>>& adj) {
    vector<int> visited(adj.size(), 0), result;
    dfsHelper(0, adj, visited, result);
    return result;
}

int main() {
    vector<vector<int>> adj = {{1, 2}, {0, 2}, {0, 1, 3, 4}, {2}, {2}};
    vector<int> dfs = dfsTraversal(adj);

    for (int node : dfs) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
