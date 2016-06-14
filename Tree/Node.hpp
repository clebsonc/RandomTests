//
// Created by clebson on 31/05/16.
//

#ifndef GRAPH_NODE_HPP
#define GRAPH_NODE_HPP


class Node {
private:
    Node * left;
    Node * right;
    int value;
public:
    /**
     * Constructor
     */
    Node();
    Node(int);
    Node(Node * left, Node * right, int const val);

    /**
     * TODO: Destructor, assignment constructor, copy constructor
     * I will let the clean up of the desctructor to be done in the BinaryTreeClass
     */

    Node * getLeft();
    Node * getRight();
    int getValue() const;
    void setValue(int const value);
    void setNodeLeft(Node * left);
    void setNodeRight(Node * right);
    void printNode();


    bool operator<(const Node & n);
    bool operator<(const Node * & n);

};


#endif //GRAPH_NODE_H
