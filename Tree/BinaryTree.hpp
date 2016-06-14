//
// Created by clebson on 31/05/16.
//

#ifndef GRAPH_BINARYTREE_HPP
#define GRAPH_BINARYTREE_HPP


#include <array>
#include <vector>
#include "Node.hpp"

class BinaryTree {
private:
    Node* root;
public:
    BinaryTree();
    BinaryTree(Node * root);

    /**
     * TODO: add constructor, destructor, copy assignment, copy constructor
     */

    bool addValue(int const & val);

    bool removeValue(int const & val);

    Node * findNode(int const value);

    int findMax();

    int findMin();

    std::vector<int> heapfyVectorValue();

//std::vector<Node*> heapfyVectorNode();
    Node* heapfyVectorNode();

    int count_nodes(Node * root);
    void transform_to_array_value(Node *h, std::vector<int> & ar);
    void transform_to_array_node(Node *h, std::vector<Node*> & ar);


    /**
     * Traversals
     */
    void preOrderTraversal(Node * root);
    void posOrderTraversal(Node * root);
    void inOrderTraversal(Node * root);
    void noRecursivePreOrderTraversal();

    /**
     * Search
     */
    Node * breadthFirstSearch();
    Node * depthFinrstSearch();


    Node * getRoot();

    int findHeight(Node * root);

    Node * findLowestCommonAncestor(int val1, int val2);

    //static bool isMenor(Node* a, Node* b);
};


#endif //GRAPH_BINARYTREE_HPP
