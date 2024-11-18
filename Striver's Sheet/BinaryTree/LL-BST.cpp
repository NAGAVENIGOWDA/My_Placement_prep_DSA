#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Definition for binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to find the middle of the linked list
ListNode* findMiddle(ListNode* start, ListNode* end) {
    ListNode* slow = start;
    ListNode* fast = start;

    while (fast != end && fast->next != end) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Function to convert sorted linked list to a balanced BST
TreeNode* sortedListToBST(ListNode* start, ListNode* end) {
    if (start == end) return NULL;

    // Find the middle element
    ListNode* mid = findMiddle(start, end);

    // Create the root node of the BST
    TreeNode* root = new TreeNode(mid->val);

    // Recursively construct the left and right subtrees
    root->left = sortedListToBST(start, mid);
    root->right = sortedListToBST(mid->next, end);

    return root;
}

// Function to print the in-order traversal of the BST
void inOrder(TreeNode* root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

int main() {
    // Create a sorted linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);

    // Convert sorted linked list to balanced BST
    TreeNode* root = sortedListToBST(head, NULL);

    // Print in-order traversal of the BST
    cout << "In-order traversal of the constructed BST: ";
    inOrder(root);

    return 0;
}
