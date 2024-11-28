// question3.cpp
// Name: [Your Name]
// Student ID: [Your Student ID]
// Date of Submission: 28-Nov-2024

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Element {
    int value;
    int arrayIndex;
    int elementIndex;

    bool operator>(const Element& other) const {
        return value > other.value;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>& arrays) {
    priority_queue<Element, vector<Element>, greater<Element>> minHeap;
    vector<int> result;

    // Insert the first element of each array into the heap
    for (int i = 0; i < arrays.size(); i++) {
        if (!arrays[i].empty()) {
            minHeap.push({arrays[i][0], i, 0});
        }
    }

    // Extract elements from the heap and insert the next elements
    while (!minHeap.empty()) {
        Element current = minHeap.top();
        minHeap.pop();
        result.push_back(current.value);

        // Insert the next element from the same array
        if (current.elementIndex + 1 < arrays[current.arrayIndex].size()) {
            minHeap.push({arrays[current.arrayIndex][current.elementIndex + 1], current.arrayIndex, current.elementIndex + 1});
        }
    }

    return result;
}

int main() {
    int k;
    cout << "Enter the number of arrays: ";
    cin >> k;
    vector<vector<int>> arrays(k);

    for (int i = 0; i < k; i++) {
        cout << "Enter elements of array " << i + 1 << " (space-separated, end with newline): ";
        int num;
        while (cin.peek() != '\n') {
            cin >> num;
            arrays[i].push_back(num);
        }
        cin.ignore();
    }

    vector<int> result = mergeKSortedArrays(arrays);
    cout << "Merged Array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
