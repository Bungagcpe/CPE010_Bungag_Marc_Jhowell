#include <cstddef>
#include <iostream>

#ifndef SELECTIONSORTSUPP_H
#define SELECTIONSORTSUPP_H

template <typename T>
int routineSmallest(T arr[], int K, const int arrSize) {
    int position = K;
    T smallestElem = arr[K];

    for (int j = K + 1; j < arrSize; j++) {
        if (arr[j] < smallestElem) {
            smallestElem = arr[j];
            position = j;
        }
    }
    return position;
}

template <typename T>
void selectionSort(T arr[], size_t arrSize) {
    int POS, temp, pass;
    for (int i = 0; i < arrSize; i++) {
        POS = routineSmallest(arr, i, arrSize);
        temp = arr[i];
        arr[i] = arr[POS];
        arr[POS] = temp;
        pass++;
    }
}
#endif