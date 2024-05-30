#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct tree {
    int data;
    tree *left;
    tree *right;
};

void insertion(tree *&root, int ele) {
    tree *newNode = new tree;
    newNode->data = ele;
    newNode->left = nullptr;
    newNode->right = nullptr;

    if (root == nullptr) {
        root = newNode;
        return;
    }

    tree *cur = root;
    tree *prev = nullptr;
    while (cur != nullptr) {
        prev = cur;
        if (ele < cur->data) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }

    if (ele < prev->data) {
        prev->left = newNode;
    } else {
        prev->right = newNode;
    }
}

void inorder(tree *root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(tree *root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(tree *root) {
    if (root == nullptr) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int search(tree *root, int K) {
    if (root == nullptr) {
        return 0;
    }
    if (root->data == K) {
        return 1;
    }
    if (K < root->data) {
        return search(root->left, K);
    } else {
        return search(root->right, K);
    }
}

tree* Delete(tree* root, int ele) {
    tree* prev = nullptr, *succ, *q;
    if (root == NULL) {
        cout << "Element not found\n";
        return NULL;
    }
    tree* cur = root;
    while (cur != NULL) {
        prev = cur;
        if (ele == cur->data) {
            break;
        }
        if (ele < cur->data)
            cur = cur->left;
        else
            cur = cur->right;
    }

    if (cur == NULL) {
        cout << "Element not found\n";
        return root;
    }

    if (cur->left == NULL)
        q = cur->right;
    else if (cur->right == NULL)
        q = cur->left;
    else {
        tree* p = NULL;
        succ = cur->right;
        while (succ->left != NULL) {
            p = succ;
            succ = succ->left;
        }
        if (p != NULL)
            p->left = succ->right;
        else
            cur->right = succ->right;

        cur->data = succ->data;
        delete succ;
        return root;
    }

    if (prev == NULL)

    {
       printf("%d is deleted\n",cur->data);
		delete (cur);
		return(q);
    }
        
    else if (cur == prev->left)
        prev->left = q;
    else
        prev->right = q;

    cout << cur->data << " is deleted\n";
    delete cur;
    return root;
}


int main() {
    tree *root = nullptr;
    tree*temp;

    int choice, x, K;
    for (;;) {
        cout << "1. Insertion\n2. Preorder\n3. Postorder\n4. Inorder\n5. Search\n6. Delete\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> x;
                insertion(root, x);
                break;
            case 2:
                preorder(root);
                cout << endl;
                break;
            case 3:
                postorder(root);
                cout << endl;
                break;
            case 4:
                inorder(root);
                cout << endl;
                break;
            case 5:
                cout << "Enter element to search: ";
                cin >> K;
                cout << search(root, K) << endl;
                break;
            case 6:
                cout << "Enter the node to be deleted: ";
                cin >> K;
               root=Delete(root, K);
              
               
                break;
           
        }
    }

    return 0;
}
