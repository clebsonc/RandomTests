#include <iostream>

#include "BinaryTree.hpp"

int main() {
    BinaryTree bt;
    bt.addValue(5);
    bt.addValue(10);
    bt.addValue(8);
    bt.addValue(9);
    bt.addValue(7);
    bt.addValue(11);
    bt.addValue(3);
    bt.addValue(2);
    bt.addValue(4);
    bt.addValue(20);
    bt.addValue(25);
    bt.addValue(30);
    //bt.noRecursivePreOrderTraversal();
    //std::cout<<""<<std::endl;
    bt.preOrderTraversal(bt.getRoot());
    std::cout<<""<<std::endl;

    /*bt.posOrderTraversal(bt.getRoot());
    std::cout<<""<<std::endl;

    bt.inOrderTraversal(bt.getRoot());
    std::cout<<""<<std::endl;

    std::cout << "Max Value: " << bt.findMax() << std::endl;
    std::cout << "Min Value: " << bt.findMin() << std::endl;

    std::cout << "Height: " << bt.findHeight(bt.getRoot()) << std::endl;
    Node * n = bt.findLowestCommonAncestor(40, 51);
    if(n)
        std::cout << "Common Ancestor: " << n->getValue() << std::endl;
    else
        std::cout << "nullptr" << std::endl;
    delete(n);*/

    bt.preOrderTraversal(bt.getRoot());

    bt.heapfyVectorValue();
    std::cout<<""<<std::endl;
    std::cout<<""<<std::endl;
    bt.preOrderTraversal(bt.heapfyVectorNode());



    return 0;
}