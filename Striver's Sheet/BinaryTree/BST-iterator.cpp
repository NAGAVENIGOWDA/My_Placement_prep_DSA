#include <iostream>
#include <stack>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

class BSTIterator {
private:
	stack<TreeNode*> st;

	void pushAllLeft(TreeNode* node) {
		while (node != nullptr) {
			st.push(node);
			node = node->left;
		}
	}

public:
	BSTIterator(TreeNode* root) {
		pushAllLeft(root);
	}

	bool hasNext() {
		return !st.empty();
	}

	int next() {
		TreeNode* node = st.top();
		st.pop();

		if (node->right != nullptr) {
			pushAllLeft(node->right);
		}

		return node->val;
	}
};

int main() {
	TreeNode* root = new TreeNode(7);
	root->left = new TreeNode(3);
	root->right = new TreeNode(15);
	root->right->left = new TreeNode(9);
	root->right->right = new TreeNode(20);

	BSTIterator iterator(root);

	while (iterator.hasNext()) {
		cout << iterator.next() << endl;
	}
	cout << endl;

	return 0;
}
