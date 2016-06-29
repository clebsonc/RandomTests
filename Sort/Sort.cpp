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

void Sort::stableSelectionSort(int *v, int n) {
    if(n!=0){
        for(int i = 0; i<n; i++){
            int miv = find_min(v, n, i);
            insert_remove(v, i, miv);
        }
    }
}

void Sort::insert_remove(int *v, int i, int minv) {
    int temp = v[minv];
    for(int j = minv; j > i; j--){
        v[j] = v[j-1];
    }
    v[i] = temp;
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


void Sort::mergeSort(int *v, int i, int j) {
    int m = (i+j)/2;
    if(i < j){
        mergeSort(v, i, m);
        mergeSort(v, m+1, j);
        merge(v, i, m, j);
    }
}

void Sort::merge(int * v, int i, int m, int j){
    int k, a, b;
    int n1 = m-i+1;
    int n2 = j - m;

    int v1[n1];
    int v2[n2];

    k = i;
    for(a=0; a < n1; a++){
        v1[a] = v[k];
        k++;
    }

    k = m+1;
    for(a = 0; a< n2; a++){
        v2[a] = v[k];
        k++;
    }

    k=i; a=0; b=0;
    while(a<n1 && b<n2){
        if(v1[a] < v2[b]){
            v[k] = v1[a];
            a++;
            k++;
        } else{
            v[k] = v2[b];
            b++;
            k++;
        }
    }

    while(a < n1){
        v[k] = v1[a];
        a++; k++;
    }
    while(b<n2){
        v[k] = v2[b];
        b++; k++;
    }
}