
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using Clock = chrono::high_resolution_clock;

long long cmpCount = 0;

// Bubble sort with early exit (best case O(n) on sorted input)
void bubbleSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            cmpCount++;
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void merge(vector<int>& a, vector<int>& tmp, int l, int m, int r) {
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r) {
        cmpCount++;
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
    }
    while (i <= m) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];
    for (int x = l; x <= r; x++) a[x] = tmp[x];
}

void mergeRec(vector<int>& a, vector<int>& tmp, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeRec(a, tmp, l, m);
    mergeRec(a, tmp, m + 1, r);
    merge(a, tmp, l, m, r);
}

void mergeSort(vector<int>& a) {
    vector<int> tmp(a.size());
    mergeRec(a, tmp, 0, (int)a.size() - 1);
}

template <class F>
void run(const char* name, F sorter, vector<int> data, const char* caseName, int n) {
    cmpCount = 0;
    auto t0 = Clock::now();
    sorter(data);
    auto t1 = Clock::now();
    double ms = chrono::duration<double, milli>(t1 - t0).count();
    bool ok = is_sorted(data.begin(), data.end());
    cout << left << setw(12) << name << setw(8) << caseName << right << setw(8) << n
         << setw(14) << cmpCount << setw(14) << fixed << setprecision(4) << ms
         << (ok ? "  sorted" : "  FAILED") << "\n";
}

int main() {
    cout << left << setw(12) << "Algorithm" << setw(8) << "Case" << right << setw(8) << "n"
         << setw(14) << "Comparisons" << setw(14) << "Time (ms)" << "\n";
    for (int n : {100, 1000, 10000}) {
        vector<int> best(n);
        iota(best.begin(), best.end(), 1);            // Already sorted
        vector<int> worst(best.rbegin(), best.rend()); // Reverse sorted
        run("Bubble", bubbleSort, best, "Best", n);
        run("Bubble", bubbleSort, worst, "Worst", n);
        run("Merge", mergeSort, best, "Best", n);
        run("Merge", mergeSort, worst, "Worst", n);
        cout << "\n";
    }
}