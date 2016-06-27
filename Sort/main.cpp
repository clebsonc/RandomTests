#include <iostream>
#include "Sort.hpp"

int main(){
    //int v[] = {7, 3, 20, 15, 13, 14};
    int v[] = {3, 7, 7, 4, 9, 5, 2, 6, 1};
    //Sort::selectionSort(v, 6);
    //Sort::insertionSort(v, 8);
    Sort::quickSort(v, 0, 8);

    for(int i = 0; i <= 8; i++){
        std::cout << v[i] << " ";
    }
    std::cout << "\n";


    return 0;
}
