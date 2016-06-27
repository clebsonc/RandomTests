#ifndef SORT_SORT_HPP
#define SORT_SORT_HPP

class Sort{
    public:
        static void selectionSort(int v[], int n);

        static int find_min(int v[], int size, int is);

        static void swap(int v[], int i, int j);

        static void insertionSort(int *v, int n);

        static void quickSort(int * v, int i, int j);
};

#endif
