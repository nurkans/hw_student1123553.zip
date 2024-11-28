// question2.cpp
// Name: [Your Name]
// Student ID: [Your Student ID]
// Date of Submission: 28-Nov-2024

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Task {
    string name;
    int priority;

    // Overload the < operator for max heap
    bool operator<(const Task& other) const {
        return priority < other.priority;
    }
};

int main() {
    priority_queue<Task> pq;
    int n;
    cout << "Enter number of operations: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string operation;
        getline(cin, operation);

        if (operation.substr(0, 3) == "ADD") {
            string name = operation.substr(4, operation.find_last_of(" ") - 4);
            int priority = stoi(operation.substr(operation.find_last_of(" ") + 1));
            pq.push({name, priority});
        } else if (operation == "GET") {
            if (!pq.empty()) {
                cout << pq.top().name << endl;
                pq.pop();
            } else {
                cout << "No tasks available!" << endl;
            }
        }
    }

    cout << "Remaining tasks: ";
    vector<Task> remaining;
    while (!pq.empty()) {
        remaining.push_back(pq.top());
        pq.pop();
    }
    sort(remaining.begin(), remaining.end(), [](Task a, Task b) { return a.priority > b.priority; });
    for (auto& task : remaining) {
        cout << "(" << task.name << ", " << task.priority << ") ";
    }
    cout << endl;

    return 0;
}
