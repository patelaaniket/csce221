#include <iostream>
using namespace std;

struct Node {
  int value;
  Node* next;
  Node(int val=0, Node *n=nullptr) : value(val), next(n) {}
};

int countNode(Node *x) {
    if (x != nullptr) {
        return 1 + countNode(x->next);
    }
    return 0;
}

int main() {
    //test number 1
    Node third(3);
    Node second(2, &third);
    Node first(1, &second);
    cout << "Test 1\nNumber of Nodes: " << countNode(&first) << endl;

    //test number 2
    Node ten(10);
    Node nine(9, &ten);
    Node eight(8, &nine);
    Node seven(7, &eight);
    Node six(6, &seven);
    cout << "Test 2\nNumber of Nodes: " << countNode(&six) << endl;
}