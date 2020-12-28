#include <iostream>
using namespace std;

struct Node {
  int value;
  Node* left;
  Node* right;

  // Node constructor
  Node(int val = 0, Node* l = nullptr, Node* r = nullptr)
    : value(val), left(l), right(r) {}
};

int countNodes(Node* parent) {
    if (parent != nullptr && parent->left && parent->right) {
        return 1 + countNodes(parent->left) + countNodes(parent->right);
    }
    return 0;
}