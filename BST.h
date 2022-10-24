#include <iostream>
#include "NodeT.h"
#include <vector>

template <class T>
class BST {
    public:
    BST();
    ~BST();
    void add(T data);
    void visit();
    void muestrax(int dato);
    private:
    NodeT<T> *root;
    void destruye(NodeT<T> *r);
    void ordenExp(NodeT<T> *r);
    vector<NodeT<T>*> tree;
};

template <class T>
BST<T>::BST() {
    root = nullptr;
}

template <class T>
BST<T>::~BST() {
    destruye(root);
}

template <class T>
void BST<T>::destruye(NodeT<T> *r) {
    if (r != nullptr) {
        destruye(r-> getLeft());
        destruye(r-> getRight());
        delete r;
    }
}

// Complejidad: O(n)
template <class T>
void BST<T>::ordenExp(NodeT<T> *r) {
    if (r != nullptr) {
        ordenExp(r-> getRight());
        tree.push_back(r);
        //cout << r-> getData() << endl;
        ordenExp(r-> getLeft());
    }
}

// Complejidad O(1)
template <class T>
void BST<T>::muestrax(int dato) {
    cout << "Los " << dato << " datos mas repetidos: " << endl;
    for (int i = 0; i < dato; i++) {
        cout << tree[i]-> getData() << endl;
    }
}

template <class T>
void BST<T>::add(T data) {
    NodeT<T> *curr = root;
    NodeT<T> *father = nullptr;
    while (curr != nullptr) {
        if (curr-> getData() == data) {
            return;
        }
        father = curr;
        curr = (curr-> getData() > data) ? 
                curr-> getLeft() : curr-> getRight();
    }
    if (father == nullptr) {
        root = new NodeT<T>(data);
    } else {
        (father-> getData() > data) ? 
                father-> setLeft(new NodeT<T>(data)) : 
                father-> setRight(new NodeT<T>(data));
    }
}

template <class T>
void BST<T>::visit() {
    ordenExp(root);
    cout << endl;
}
