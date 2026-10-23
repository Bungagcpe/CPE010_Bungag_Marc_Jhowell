#ifndef SORTINGALGO_H
#define SORTINGALGO_H

#include <cstddef>
#include <iostream>

// SHELL SORT
template <typename T>
void shellSort(T data[], size_t size) {
    size_t step = size / 2;

    while (step > 0) {
        for (size_t current = step; current < size; current++) {
            T value = data[current];
            int position = current;

            while (position >= (int)step &&
                   data[position - step] > value) {
                data[position] = data[position - step];
                position -= step;
            }
            data[position] = value;
        }
        step /= 2;
    }
}


// MERGE SORT
template <typename T>
void combine(T data[], int start, int mid, int end) {
    T sorted[100];

    int first = start;
    int second = mid + 1;
    int index = 0;

    while (first <= mid || second <= end) {

        if (second > end ||
            (first <= mid && data[first] <= data[second])) {
            sorted[index] = data[first];
            first++;
        }
        else {
            sorted[index] = data[second];
            second++;
        }
        index++;
    }

    for (int x = 0; x < index; x++) {
        data[start + x] = sorted[x];
    }
}

template <typename T>
void mergeSort(T data[], int start, int end) {
    if (start >= end)
        return;

    int mid = start + (end - start) / 2;

    mergeSort(data, start, mid);
    mergeSort(data, mid + 1, end);

    combine(data, start, mid, end);
}


// QUICK SORT
template <typename T>
int split(T data[], int first, int last) {

    T pivot = data[first];
    int left = first + 1;
    int right = last;

    while (left <= right) {

        while (left <= last && data[left] <= pivot)
            left++;

        while (data[right] > pivot)
            right--;

        if (left < right) {
            std::swap(data[left], data[right]);
        }
    }

    std::swap(data[first], data[right]);

    return right;
}

template <typename T>
void quickSort(T data[], int first, int last) {
    if (first >= last)
        return;

    int position = split(data, first, last);

    quickSort(data, first, position - 1);
    quickSort(data, position + 1, last);
}

#endif