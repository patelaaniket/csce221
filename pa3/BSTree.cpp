#include "BSTree.h"

#include <iostream>
#include <queue>

using namespace std;

// input / output operators
ostream& operator<<(ostream& out, BSTree& tree) {
    tree.print_level_by_level(out);
    return out;
}

ostream& operator<<(ostream& out, Node& node) {
    return out << node.value << "[" << node.search_time << "]";
}

istream& operator>>(istream& in, BSTree& tree) {
    int next;
    while(in >> next) {
        tree.insert(next);
    }
    return in;
}

// Example recursive function
void BSTree::copy_helper(Node*& newNode, const Node* sourceNode) {
    //Don't copy if the node is nullptr
    if(sourceNode == nullptr)
        return;

    //Change the new node to a copy of sourceNode
    newNode = new Node(sourceNode->value);
    //Copy over the search cost
    newNode->search_time = sourceNode->search_time;

    //Copy left subtree
    if (sourceNode->left != nullptr)
        copy_helper(newNode->left, sourceNode->left);
    //Copy right subtree
    if(sourceNode->right != nullptr)
        copy_helper(newNode->right, sourceNode->right);
}

// recursive function
int BSTree::get_total_search_time(Node* node) {
    if (node != nullptr) {
        return node->search_time + get_total_search_time(node->left) + get_total_search_time(node->right);
    }
    return 0;
}

// implemented
float BSTree::get_average_search_time() {
    int total_search_time = get_total_search_time(root);
    if(total_search_time == 0)
        return -1;
    
    return ((float)total_search_time)/size;
}

//recursive function to help copy nodes
void copier(const Node* from, Node* &to) {
    if (from == nullptr) {
        to = nullptr;
    }
    else {
        to = new Node(from->value);
        to->search_time = from->search_time;
        copier(from->left, to->left); 
        copier(from->right, to->right);
    }
}

// copy constructor
BSTree::BSTree(const BSTree& other) {
    this->size = other.size;
    copier(other.root, this->root);
}

// move constructor
BSTree::BSTree(BSTree&& other) {
    this->root = other.root;
    this->size = other.size;
    other.root = nullptr;
    other.size = 0;
}

//copy assignment
BSTree& BSTree::operator=(const BSTree& other) {
    if (this != &other) {
        if (this->root != nullptr) {
            this->~BSTree();
        }
        this->size = other.size;
        copier(other.root, this->root);
    }
    return *this;
}

// move assignment
BSTree& BSTree::operator=(BSTree&& other) {
    if (this != &other) {
        if (this->root != nullptr) {
            this->~BSTree();
        }
        this->root = other.root;
        this->size = other.size;
        other.root = nullptr;
        other.size = 0;
    }
    return *this;
}

//recursive function to help delete nodes
void deleter(Node* &del) {
    if (del != nullptr) {
        deleter(del->left);
        deleter(del->right);
        delete del;
    }
}

// destructor
BSTree::~BSTree() {
    deleter(this->root);
}

//recursive function to help insert nodes
void inserter(Node* &obj, Node* &parent) {
    if (parent == nullptr) {
        parent = obj;
    }
    else if (parent->value > obj->value) {
        obj->search_time++;
        inserter(obj, parent->left);
    }
    else {
        obj->search_time++;
        inserter(obj, parent->right);
    }
}

Node* BSTree::insert(int obj) {
    Node *add = new Node(obj);
    add->search_time++;
    inserter(add, this->root);
    size++;
    return add;
}

//recursive function to help find nodes
Node* finder(Node* parent, int obj) {
    if (parent->value > obj) {
        if (parent->left != nullptr) {
            finder(parent->left, obj);
        }
    }
    else if (parent->value < obj) {
        if (parent->right != nullptr) {
            finder(parent->right, obj);
        }
    }
    else {
        return parent;
    }
}

Node* BSTree::search(int obj) {
    Node* idx = nullptr;
    if (this->root != nullptr) {
        idx = finder(this->root, obj);
    }
    return idx;
}

//recursive function to help assign search time to nodes
void timer(Node* parent, int time) {
    parent->search_time = time;
    if (parent->left) {    
        timer(parent->left, time + 1);
    }
    if (parent->right) {
        timer(parent->right, time + 1);
    }
}

void BSTree::update_search_times() {
    /* do a BFS or DFS of your tree and update the search times of all nodes at once
      The root has a search time of 1, and each child is 1 more than its parent */
    timer(this->root, 1);
}

//recursive function to help print tree in inorder
void printInOrder(Node* parent, ostream& out) {
    if (parent != nullptr) {
        printInOrder(parent->left, out);
        out << parent->value << "[" << parent->search_time << "] ";
        printInOrder(parent->right, out);
    }
}

void BSTree::inorder(ostream& out) {
    /* print your nodes in infix order
    If our tree looks like this:

       4
     2   6
    1 3 5 7

    It should output:
    1[3] 2[2] 3[3] 4[1] 5[3] 6[2] 7[3]
    You can use the << operator to print the nodes in the format shown */
    printInOrder(this->root, out);
    out << endl;
}

int height(Node* parent) {
    if (parent == NULL) {
        return 0;
    }
    else {  
        int lheight = height(parent->left);
        int rheight = height(parent->right);
  
        if (lheight > rheight) {
            return(lheight + 1);
        }
        else {
            return(rheight + 1);
        }
    } 
}

void printLevel(Node* parent, int lev, ostream &out) {  
    if (parent == nullptr) {
        out << "X ";
        return;
    }
    if (lev == 1) {
        out << parent->value << "[" << parent->search_time << "] ";  
    }
    else if (lev > 1) {  
        printLevel(parent->left, lev-1, out);  
        printLevel(parent->right, lev-1, out);  
    }  
} 

void BSTree::print_level_by_level(ostream& out) {
    // for(int i = 1; i <= height(this->root); i++) {
    //     printLevel(this->root, i, out);
    //     out << endl;
    // }
    // queue<Node*> q; // This queue contains elements from a level and its children
    // q.push(root);
    // int elementsInLevel = 1; // Elements in the current level
    // bool nonNullChild = false;
    // while (elementsInLevel > 0) {
    //     Node* node = q.front();
    //     q.pop();
    //     elementsInLevel--;
    //     if (node != nullptr) {
    //         out << node->value << "[" << node->search_time << "] ";
    //         if (node->left != nullptr) {
    //             q.push(node->left); 
    //         }
    //         if (node->right != nullptr) {
    //             q.push(node->right); 
    //         }
    //         if (node->left != nullptr || node->right != nullptr) {
    //             nonNullChild = true;
    //         }
    //     }
    //     else {
    //         out << 'X';
    //         q.push(nullptr);// these nulls represent the descendants of the empty node
    //         q.push(nullptr);
    //     }
    //     if (elementsInLevel == 0) {// We have reached the end of the current level
    //         out << endl;
    //         if (nonNullChild == true) { // The next level is non-empty
    //             nonNullChild = false;
    //             elementsInLevel = q.size();
    //         }
    //     }
    // }
    if (this->root) {
        bool notEmpty = true;
        vector<Node*> cl;
        vector<Node*> nl;
        cl.push_back(this->root);
        while(notEmpty) {
            notEmpty = false;
            for(auto i : cl) {
                if (i) {
                    out << i->value << "[" << i->search_time << "] ";
                    if (i->left || i->right) {
                        notEmpty = true;
                    }
                    nl.push_back(i->left);
                    nl.push_back(i->right);
                }
                else {
                    out << "X ";
                    nl.push_back(nullptr);
                    nl.push_back(nullptr);
                }
            }
            out << endl;
            cl.clear();
            cl = nl;
            nl.clear();
        }
    }
}