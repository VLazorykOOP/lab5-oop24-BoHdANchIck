#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node* root;

    void insertHelper(Node* node, int value) {
        if (value < node->data) {
            if (node->left == nullptr) {
                node->left = new Node(value);
            }
            else {
                insertHelper(node->left, value);
            }
        }
        else {
            if (node->right == nullptr) {
                node->right = new Node(value);
            }
            else {
                insertHelper(node->right, value);
            }
        }
    }

    
    void LeftRight(Node* root) {
        if (root != nullptr) {
            std::cout << root->data << " ";
            LeftRight(root->left);
            LeftRight(root->right);
        }
    }

    void RightLeft(Node* root) {
        if (root != nullptr) {
            std::cout << root->data << " ";
            RightLeft(root->right);
            RightLeft(root->left);
        }
    }
public:
    BinaryTree() : root(nullptr) {}

    void insert(int value) {
        if (root == nullptr) {
            root = new Node(value);
        }
        else {
            insertHelper(root, value);
        }
    }

    void LeftRight() {
        std::cout << "Your tree: ";
        LeftRight(root);
        std::cout << std::endl;
    }

    void RightLeft() {
        std::cout << "Your tree: ";
        RightLeft(root);
        std::cout << std::endl;
    }
};

int main() {
    BinaryTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);
    tree.insert(1);
    tree.insert(10);
    
    tree.LeftRight();
    tree.RightLeft();
    return 0;
}
