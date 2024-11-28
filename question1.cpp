// question1.cpp
// Name: [Your Name]
// Student ID: [Your Student ID]
// Date of Submission: 28-Nov-2024

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to build a binary tree from level-order input
TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return NULL;

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (nodes[i] != -1) {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != -1) {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

// Helper function to calculate the height and update the diameter
int calculateDiameter(TreeNode* root, int& diameter) {
    if (!root) return 0;

    int leftHeight = calculateDiameter(root->left, diameter);
    int rightHeight = calculateDiameter(root->right, diameter);

    // Update diameter if the current path is longer
    diameter = max(diameter, leftHeight + rightHeight);

    // Return height of the current node
    return 1 + max(leftHeight, rightHeight);
}

// Function to find the diameter of the binary tree
int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    calculateDiameter(root, diameter);
    return diameter;
}

int main() {
    vector<int> nodes = {1, 2, 3, 4, 5, -1, -1, -1, -1, 6, 7};
    TreeNode* root = buildTree(nodes);

    cout << "The diameter of the binary tree is: " << diameterOfBinaryTree(root) << endl;

    return 0;
}
