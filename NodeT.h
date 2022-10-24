#include <iostream>
using namespace std;

template <class T>
class NodeT{
    public:
    NodeT(T data);
    NodeT(T data, NodeT<T>* left, NodeT<T>* right);
    T getData();
    NodeT<T>* getLeft();
    NodeT<T>* getRight();
    void setData(T data);
    void setLeft(NodeT<T> *left);
    void setRight(NodeT<T> *right);
    private: 
    T data;
    NodeT<T> *left;
    NodeT<T> *right;
};

template <class T>
NodeT<T>::NodeT(T data) {
    this-> data = data;
    this-> left = nullptr;
    this-> right = nullptr;
}

template <class T>
NodeT<T>::NodeT(T data, NodeT<T> *left, NodeT<T> *right) {
    this-> data = data;
    this-> left = left;
    this-> right = right;
}

template <class T>
T NodeT<T>::getData() {
    return data;
}

template <class T>
NodeT<T>* NodeT<T>::getLeft() {
    return left;
}


template <class T>
NodeT<T>* NodeT<T>::getRight() {
    return right;
}

template <class T>
void NodeT<T>::setData(T data) {
    this-> data = data;
}

template <class T>
void NodeT<T>::setLeft(NodeT<T> *left) {
    this-> left = left;
}

template <class T>
void NodeT<T>::setRight(NodeT<T> *right) {
    this-> right = right;
}