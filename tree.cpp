#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    // Constructor to create a new node
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Function to insert a node in the binary tree
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);  // Create a new node if the tree is empty
    }

    if (value < root->data) {
        root->left = insert(root->left, value);  // Insert in the left subtree
    } else {
        root->right = insert(root->right, value);  // Insert in the right subtree
    }
    return root;
}

// In-order traversal (Left, Root, Right)
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

// Pre-order traversal (Root, Left, Right)
void preorderTraversal(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Post-order traversal (Left, Right, Root)
void postorderTraversal(Node* root) {
    if (root != nullptr) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }
}

// Function to search for a value in the binary tree
bool search(Node* root, int key) {
    if (root == nullptr) {
        return false;  // Key not found
    }
    
    if (root->data == key) {
        return true;  // Key found
    } else if (key < root->data) {
        return search(root->left, key);  // Search in the left subtree
    } else {
        return search(root->right, key);  // Search in the right subtree
    }
}

int main() {
    Node* root = nullptr;  // Create an empty tree

    // Insert nodes into the tree
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Traversals
    cout << "In-order Traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Pre-order Traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Post-order Traversal: ";
    postorderTraversal(root);
    cout << endl;

    // Search for a key in the tree
    int key = 40;
    if (search(root, key)) {
        cout << "Key " << key << " found in the tree." << endl;
    } else {
        cout << "Key " << key << " not found in the tree." << endl;
    }

    return 0;
}
