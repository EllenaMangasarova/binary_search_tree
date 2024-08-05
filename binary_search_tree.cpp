#include <iostream>

class TreeNode {
public:
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int k) : key(k), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, int key) {
        if (node == nullptr) {
            return new TreeNode(key);
        }
        if (key < node->key) {
            node->left = insert(node->left, key);
        } else if (key > node->key) {
            node->right = insert(node->right, key);
        }
        return node;
    }

    TreeNode* erase(TreeNode* node, int key) {
        if (node == nullptr) {
            return node;
        }
        if (key < node->key) {
            node->left = erase(node->left, key);
        } else if (key > node->key) {
            node->right = erase(node->right, key);
        } else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            TreeNode* temp = node->right;
            while (temp && temp->left != nullptr) {
                temp = temp->left;
            }
            node->key = temp->key;
            node->right = erase(node->right, temp->key);
        }
        return node;
    }

    bool find(TreeNode* node, int key) {
        if (node == nullptr) {
            return false;
        }
        if (key < node->key) {
            return find(node->left, key);
        } else if (key > node->key) {
            return find(node->right, key);
        } else {
            return true;
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int key) {
        root = insert(root, key);
    }

    void erase(int key) {
        root = erase(root, key);
    }

    bool find(int key) {
        return find(root, key);
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    std::cout << "Find 40: " << (bst.find(40) ? "Found" : "Not Found") << std::endl;
    std::cout << "Find 90: " << (bst.find(90) ? "Found" : "Not Found") << std::endl;

    bst.erase(20);
    std::cout << "Find 20 after deletion: " << (bst.find(20) ? "Found" : "Not Found") << std::endl;

    bst.erase(30);
    std::cout << "Find 30 after deletion: " << (bst.find(30) ? "Found" : "Not Found") << std::endl;

    bst.erase(50);
    std::cout << "Find 50 after deletion: " << (bst.find(50) ? "Found" : "Not Found") << std::endl;

    return 0;
}
