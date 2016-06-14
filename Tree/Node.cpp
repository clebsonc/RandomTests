//
// Created by clebson on 31/05/16.
//

#include<iostream>
#include "Node.hpp"


Node::Node() {
    this->left = nullptr;
    this->right = nullptr;
}

Node::Node(int val):value(val), right(nullptr), left(nullptr){
}

Node::Node(Node * left, Node * right, int const val) {
    this->left = left;
    this->right = right;
    this->value = val;
}

Node * Node::getLeft() {
    return this->left;
}

Node * Node::getRight() {
    return this->right;
}

int Node::getValue() const{
    return this->value;
}

void Node::setNodeLeft(Node *left) {
    this->left = left;
}

void Node::setNodeRight(Node *right) {
    this->right = right;
}

void Node::setValue(int const value) {
    this->value = value;
}

void Node::printNode() {
    std::cout << "Node Value " << this->value << "\tLeft: " << this->left << "\tRight: " << this->right;
}

bool Node::operator<(const Node &n) {
    std::cout << "\nr: " << this->getValue() << " " ;
    std::cout << "n: " << n.getValue() << std::endl;
    return this->value < n.getValue();
}

bool Node::operator<(const Node * & n){
    return this->getValue() < n->getValue();
}