#include <iostream>
#include <iomanip>
#include <vector>
#include <chrono>

bool uniqueArr(const std::vector<int>& A, long long& cnt) {
    int n = A.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++) {
            cnt++;
            if (A[i] == A[j]) return false;
        }
    return true;
}

int main() {
    std::cout << std::setw(8) << "n" << std::setw(16) << "count"
              << std::setw(16) << "n(n-1)/2" << std::setw(14) << "time(us)" << "\n";
    for (int n : {1000, 2000, 4000, 8000, 16000}) {
        std::vector<int> A(n);
        for (int i = 0; i < n; i++) A[i] = i;
        long long cnt = 0;
        auto b = std::chrono::steady_clock::now();
        uniqueArr(A, cnt);
        auto e = std::chrono::steady_clock::now();
        std::cout << std::setw(8) << n << std::setw(16) << cnt
                  << std::setw(16) << (long long)n * (n - 1) / 2
                  << std::setw(14)
                  << std::chrono::duration_cast<std::chrono::microseconds>(e - b).count()
                  << "\n";
    }
}