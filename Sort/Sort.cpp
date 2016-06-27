#include "Sort.hpp"
#include <iostream>

void Sort::selectionSort(int v[], int n){
    for(int i = 0; i < (n-1); i++){
        int j = find_min(v, n, i);
        swap(v, i, j);
    }
}

int Sort::find_min(int  v[], int size, int is){
    int min = is;
    for(int i = is + 1; i < size; i++){
        if(v[i] < v[min]){
            min = i;
        }
    }
    return min;
}

void Sort::swap(int v[], int i, int j){
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}


void Sort::insertionSort(int *v, int n) {
    for(int i = 0; i < n; i++) {
        int max = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > max) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = max;
    }
}

void Sort::quickSort(int *v, int i, int j) {
    int pivot = v[(j-i)/2 + i];
    int k = i, l = j;

    while(k <= l){
        while(v[k] < pivot){
            k++;
        }
        while(v[l]>pivot){
            l--;
        }
        if(k<=l){
            int temp = v[k];
            v[k] = v[l];
            v[l] = temp;
            k++;
            l--;
        }
    }
    if(i<l)
        quickSort(v, i, l);
    if(k<j)
        quickSort(v, k, j);

}

