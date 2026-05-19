#ifndef SORT_SEARCH_ALGO_H
#define SORT_SEARCH_ALGO_H
#include <vector>
#include "../App/app.h"
using namespace std;

double get_cpu_time_ms();

void merge(vector<app> &arr, int left, int mid, int right);
void mergeSort(vector<app> &arr, int left, int right);

int partition(vector<app> &arr, int low, int high);
void quickSort(vector<app> &arr, int low, int high);

int binarySearch(vector<app> &arr, string appName);
int linearSearch(vector<app> &arr, string appName);
int sentinelLinearSearch(vector<app> &arr, int n, string target);

#endif