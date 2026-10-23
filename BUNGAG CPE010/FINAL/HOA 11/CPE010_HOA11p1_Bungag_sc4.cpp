#include <iostream>
#include <iomanip>
#include <chrono>

double rpower(double x, int n, long long& c) {
    if (n == 0) return 1;
    c++;
    return x * rpower(x, n - 1, c);
}

double brpower(double x, int n, long long& c) {
    if (n == 0) return 1;
    if (n % 2 == 1) {
        double y = brpower(x, (n - 1) / 2, c);
        c += 2;
        return x * y * y;
    }
    double y = brpower(x, n / 2, c);
    c++;
    return y * y;
}

int main() {
    std::cout << std::setw(8) << "n" << std::setw(12) << "rp mult"
              << std::setw(12) << "rp ns" << std::setw(12) << "brp mult"
              << std::setw(12) << "brp ns" << "\n";
    for (int n : {1000, 2000, 4000, 8000, 16000}) {
        long long c1 = 0, c2 = 0;
        auto t0 = std::chrono::steady_clock::now();
        rpower(1.0001, n, c1);
        auto t1 = std::chrono::steady_clock::now();
        brpower(1.0001, n, c2);
        auto t2 = std::chrono::steady_clock::now();
        std::cout << std::setw(8) << n << std::setw(12) << c1
                  << std::setw(12)
                  << std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count()
                  << std::setw(12) << c2
                  << std::setw(12)
                  << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
                  << "\n";
    }
}