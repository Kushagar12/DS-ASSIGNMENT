#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int v) {
        data = v;
        left = right = NULL;
    }
};

class BST {
    Node* root;

    Node* insertNode(Node* node, int key) {
        if (!node) return new Node(key);
        if (key < node->data) node->left = insertNode(node->left, key);
        else if (key > node->data) node->right = insertNode(node->right, key);
        return node;
    }

    Node* minValueNode(Node* node) {
        Node* curr = node;
        while (curr && curr->left) curr = curr->left;
        return curr;
    }

    Node* deleteNode(Node* node, int key) {
        if (!node) return node;
        if (key < node->data) node->left = deleteNode(node->left, key);
        else if (key > node->data) node->right = deleteNode(node->right, key);
        else {
            if (!node->left) {
                Node* t = node->right;
                delete node;
                return t;
            }
            if (!node->right) {
                Node* t = node->left;
                delete node;
                return t;
            }
            Node* t = minValueNode(node->right);
            node->data = t->data;
            node->right = deleteNode(node->right, t->data);
        }
        return node;
    }

    int maxDepth(Node* root) {
    if(root == NULL)
        return 0;

    int leftDepth  = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return 1 + max(leftDepth, rightDepth);
}

    int minDepth(Node* root) {
    if(root == NULL)
        return 0;

    
    if(root->left == NULL)
        return 1 + minDepth(root->right);

    
    if(root->right == NULL)
        return 1 + minDepth(root->left);

    
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

public:
    BST() {
        root = NULL;
    }

    void insert(int key) {
        root = insertNode(root, key);
    }

    void remove(int key) {
        root = deleteNode(root, key);
    }

    int getMaxDepth() {
        return maxDepth(root);
    }

    int getMinDepth() {
        return minDepth(root);
    }
};

int main() {
    BST tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(20);
    tree.insert(3);
    tree.insert(7);

    cout << "Max Depth: " << tree.getMaxDepth() << endl;
    cout << "Min Depth: " << tree.getMinDepth() << endl;

    tree.remove(5);

    cout << "After deletion, Max Depth: " << tree.getMaxDepth() << endl;
    cout << "After deletion, Min Depth: " << tree.getMinDepth() << endl;
}

