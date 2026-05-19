#include <chrono>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

double get_cpu_time_ms()
{
    auto now = chrono::high_resolution_clock::now();
    auto duration = now.time_since_epoch();
    return chrono::duration<double, milli>(duration).count();
}

int main()
{
    double start_time = get_cpu_time_ms();

    // ==================== PUT YOUR LOGIC HERE ====================
    std::vector<int> data(100000, 0);

    // insertionSort(data);
    // bubbleSort(data);
    // ==================== END OF YOUR LOGIC ====================

    double end_time = get_cpu_time_ms();
    double cpu_time_ms = end_time - start_time;

    std::cout << std::fixed << std::setprecision(8);
    std::cout << "CPU Time: " << cpu_time_ms << " ms" << std::endl;

    return 0;
}