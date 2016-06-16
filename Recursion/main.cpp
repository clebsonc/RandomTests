#include <iostream>
#include <array>

int binary_search(int * vetor, int start, int end, int value){
    int mid = start + (end-start) / 2;
    try{
        if(vetor[start] > vetor[end])
            throw new std::logic_error("Vetor is not sorted");
        if(vetor[mid] == value){
            return mid;
        } else if(start == end){ // the element is not on the list
            return -1;
        } else if (value < vetor[mid]){
            return binary_search(vetor, start, mid-1, value);
        } else {
            return binary_search(vetor, mid+1, end, value);
        }
    } catch (std::logic_error * le){
        std::cout << le->what() << std::endl;
        delete(le);
        return -1;
    }
}

int main() {
    int vetor[10] = {41, 7, 15, 16, 18, 19, 30, 33, 40, 2};

    int index = binary_search(vetor, 0, 9, 1);
    std::cout << "index " << index << std::endl;

    return 0;
}