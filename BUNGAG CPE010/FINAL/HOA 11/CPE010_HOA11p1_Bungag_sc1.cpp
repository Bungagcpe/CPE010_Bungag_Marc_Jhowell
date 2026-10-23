#include <iostream>
#include <iomanip>
#include <vector>

long long comparisons = 0;

int search(const std::vector<int>& x, int target) {
    for (int i = 0; i < (int)x.size(); i++) {
        comparisons++;
        if (x[i] == target) return i;
    }
    return -1;
}

bool diff(const std::vector<int>& x, const std::vector<int>& y) {
    for (int i = 0; i < (int)y.size(); i++) {
        if (search(x, y[i]) != -1) {
            return false;
        }
    }
    return true;
}

int main() {
    std::cout << std::setw(8) << "n" << std::setw(16) << "comparisons"
              << std::setw(16) << "n^2" << "\n";
    for (int n : {10, 20, 30, 100, 200}) {
        std::vector<int> x(n), y(n);
        for (int i = 0; i < n; i++) {
            x[i] = i;
            y[i] = i + n;
        }
        comparisons = 0;
        diff(x, y);
        std::cout << std::setw(8) << n << std::setw(16) << comparisons
                  << std::setw(16) << (long long)n * n << "\n";
    }
    return 0;
}