//
// Created by clebson on 31/05/16.
//

#include "BinaryTree.hpp"
#include <new>
#include <iostream>
#include <stack>
#include <algorithm>

BinaryTree::BinaryTree() : root(nullptr) { }

BinaryTree::BinaryTree(Node *root) : root(root){ }

bool BinaryTree::addValue(int const &val) {
    Node * nNode;
    try {
        nNode = new Node(val);
    } catch (std::bad_alloc e){
        std::cout << "Error while allocating memory" << std::endl;
        std::cout << e.what();
        return false;
    }

    Node * aux = this->root;
    if(root == nullptr){
        root = nNode;
        return true;
    }

    while(true){
        if(val < aux->getValue()){
            if(aux->getLeft()!=nullptr){
                aux = aux->getLeft();
            } else{
                aux->setNodeLeft(nNode);
                return true;
            }
        } else{
            if(aux->getRight()!=nullptr){
                aux = aux->getRight();
            } else{
                aux->setNodeRight(nNode);
                return true;
            } // end else
        } // end else
    } // end while
} // end function


void BinaryTree::preOrderTraversal(Node * root /* nullptr*/) {
    if(root == nullptr)
        return;
    std::cout << root -> getValue() << " ";
    preOrderTraversal(root->getLeft());
    preOrderTraversal(root->getRight());
}

void BinaryTree::posOrderTraversal(Node * root /* nullptr*/) {
    if(root == nullptr)
        return;
    posOrderTraversal(root->getLeft());
    posOrderTraversal(root->getRight());
    std::cout << root -> getValue() << " ";
}

void BinaryTree::inOrderTraversal(Node * root /* nullptr*/) {
    if(root == nullptr)
        return;
    inOrderTraversal(root->getLeft());
    std::cout << root -> getValue() << " ";
    inOrderTraversal(root->getRight());
}

Node * BinaryTree::getRoot(){
    return this->root;
}

int BinaryTree::findMax() {
    Node * aux = root;
    if(aux == nullptr){
        std::cout << "The tree is empty" << std::endl;
    }

    while(aux->getRight()!=nullptr){
        aux = aux->getRight();
    }

    return aux->getValue();
}

int BinaryTree::findMin() {
    Node * aux = root;
    if(aux == nullptr){
        std::cout << "The tree is empty" << std::endl;
    }

    while(aux->getLeft()!=nullptr){
        aux = aux->getLeft();
    }

    return aux->getValue();
}

Node * BinaryTree::findNode(int const value){
    if(this->root == nullptr)
        return nullptr;
    Node * aux = this->root;
    while(aux!=nullptr){
        if(aux->getValue() == value){
            return aux;
        }
        if(value <= aux->getValue()){
            aux = aux->getLeft();
        } else{
            aux = aux->getRight();
        }
    }
    return aux;
}


int BinaryTree::findHeight(Node *root) {
    if(root->getLeft() == nullptr && root->getRight() == nullptr){
        return 1;
    }

    int hl=0, hr=0;
    if(root->getLeft() != nullptr)
        hl = 1+findHeight(root->getLeft());
    if(root->getRight() != nullptr)
        hr = 1+findHeight(root->getRight());
    return hl > hr ? hl : hr;
}


void BinaryTree::noRecursivePreOrderTraversal() {
    std::stack<Node*> myStack;
    if(this->root== nullptr){
        std::cout << "The stack is Empty";
        return;
    }
    myStack.push(this->root);
    Node * aux = nullptr;
    while(!myStack.empty()){
        aux = myStack.top();
        myStack.pop();
        while(aux){ //while aux != nullptr
            std::cout<< aux->getValue() << " ";
            if(aux->getRight())
                myStack.push(aux->getRight());
            aux = aux->getLeft();
        }
    }
}


Node * BinaryTree::findLowestCommonAncestor(int val1, int val2) {
    Node * aux = this->getRoot();
    while(aux!=nullptr) {
        std::cout << "Reading aux " << aux->getValue() << std::endl;
        if (val1 < aux->getValue() && val2 < aux->getValue()){
            if(aux->getLeft()== nullptr) {
                std::cout << "Returning nullptr" << std::endl;
                return nullptr;
            }else if( aux->getLeft()->getValue() != val1 &&
                aux->getLeft()->getValue() != val2){
                aux = aux->getLeft();
            }
        }
        else if(val1 > aux->getValue() && val2 > aux->getValue()){
            if(aux->getRight()== nullptr) {
                std::cout << "returning nullptr" << std::endl;
                return nullptr;
            } else if(aux->getRight()->getValue() != val1 &&
                aux->getRight()->getValue() != val2){
                aux = aux->getRight();
            }
        }
    }
}

int BinaryTree::count_nodes(Node * h) {
    int n = 0;
    if(h==nullptr){
        return n;
    }
    n += count_nodes(h->getLeft())+1;
    n += count_nodes(h->getRight());
    return n;
}


void BinaryTree::transform_to_array_value(Node *h, std::vector<int> &ar) {
    if(h==nullptr){
        return;
    }
    transform_to_array_value(h->getLeft(), ar);
    transform_to_array_value(h->getRight(), ar);
    ar.push_back(h->getValue());
}

void BinaryTree::transform_to_array_node(Node *h, std::vector<Node*> &ar) {
    if(h==nullptr){
        return;
    }
    transform_to_array_node(h->getLeft(), ar);
    transform_to_array_node(h->getRight(), ar);
    ar.push_back(h);
}

/**
 * Heapify returning a vector representation
 */
std::vector<int> BinaryTree::heapfyVectorValue(){
    int n = count_nodes(this->root);
    std::vector<int> heap;
    transform_to_array_value(this->root, heap);
    std::sort(heap.rbegin(), heap.rend());
    std::cout << "\nHeap is: " << std::endl;
    for(int i : heap){
        std::cout << i << " ";
    }
    return heap;
}

bool isMenor (Node* a, Node* b){
    return a->getValue() < b->getValue();
}


//std::vector<Node*> BinaryTree::heapfyVectorNode() {
Node * BinaryTree::heapfyVectorNode() {
    int n = count_nodes(this->root);
    std::vector<Node*> heap;
    transform_to_array_node(this->root, heap);
    std::sort(heap.begin(), heap.end(), isMenor);


    std::cout << "\nHeap is: " << std::endl;
    for(Node * i : heap){
        std::cout << i->getValue() << " ";
    }
    std::cout << "\n" << std::endl;
    std::vector<Node*>::iterator it = heap.begin();
    for(int i = 0; i < n ; i++){
        if(i<=(n-2)/2) {
//        std::cout << "i: " << i << " " ;
            (*it)->setNodeLeft(heap[2 * i + 1]);
            (*it)->setNodeRight(heap[2 * i + 2]);
            it++;
        } else{
             (*it)->setNodeLeft(nullptr);
            (*it)->setNodeRight(nullptr);
            it++;
        }
    }
    //std::cout << "\n";

    return heap.at(0);
}

