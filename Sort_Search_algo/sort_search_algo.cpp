#include <vector>
#include <chrono>
#include "../App/app.h"
#include "sort_search_algo.h"
using namespace std;

double get_cpu_time_ms()
{
    auto now = chrono::high_resolution_clock::now();
    auto duration = now.time_since_epoch();
    return chrono::duration<double, milli>(duration).count();
}

void merge(vector<app> &arr, int left, int mid, int right)
{

    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<app> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (L[i].getAppName() <= R[j].getAppName())
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<app> &arr, int left, int right)
{

    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int partition(vector<app> &arr, int low, int high)
{
    string pivot = arr[high].getAppName();
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j].getAppName() <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<app> &arr, int low, int high)
{

    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int binarySearch(vector<app> &arr, string appName)
{
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid].getAppName() == appName)
            return mid;

        if (arr[mid].getAppName() < appName)
            low = mid + 1;

        else
            high = mid - 1;
    }
    return -1;
}

int linearSearch(vector<app> &arr, string appName)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i].getAppName() == appName)
            return i;
    }
    return -1;
}

int sentinelLinearSearch(vector<app> &arr, int n, string target)
{
    string last = arr[n - 1].getAppName();
    arr[n - 1].getAppName() = target;
    int i = 0;
    while (arr[i].getAppName() != target)
    {
        i++;
    }
    arr[n - 1].getAppName() = last;
    if ((i < n - 1) || (last == target))
    {
        return i;
    }
    return -1;
}