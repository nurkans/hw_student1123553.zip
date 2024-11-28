// question4.cpp
// Name: [Your Name]
// Student ID: [Your Student ID]
// Date of Submission: 28-Nov-2024

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Task {
    int profit;
    int deadline;
};

bool compare(Task a, Task b) {
    return a.profit > b.profit;
}

int scheduleTasks(vector<Task>& tasks) {
    sort(tasks.begin(), tasks.end(), compare);
    int maxDeadline = 0;

    for (auto& task : tasks) {
        maxDeadline = max(maxDeadline, task.deadline);
    }

    vector<int> slots(maxDeadline, -1);
    int maxProfit = 0;

    for (auto& task : tasks) {
        for (int i = task.deadline - 1; i >= 0; i--) {
            if (slots[i] == -1) {
                slots[i] = task.profit;
                maxProfit += task.profit;
                break;
            }
        }
    }

    cout << "Scheduled Tasks: ";
    for (int i = 0; i < slots.size(); i++) {
        if (slots[i] != -1) {
            cout << slots[i] << " ";
        }
    }
    cout << endl;

    return maxProfit;
}

int main() {
    int n;
    cout << "Enter number of tasks: ";
    cin >> n;

    vector<Task> tasks(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter profit and deadline for task " << i + 1 << ": ";
        cin >> tasks[i].profit >> tasks[i].deadline;
    }

    int maxProfit = scheduleTasks(tasks);
    cout << "Maximum Profit: " << maxProfit << endl;

    return 0;
}
