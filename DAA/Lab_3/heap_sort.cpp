#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int> &arr, int N, int index) {
  for (int i = 0; i < N; ++i) {
    cout << arr[i] << (index == i ? " | " : " ");
  }
  cout << endl;
}

void heapify(vector<int> &arr, int N, int i) {
  int root = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < N && arr[l] > arr[root]) {
    root = l;
  }

  if (r < N && arr[r] > arr[root]) {
    root = r;
  }

  //   cout << "After heapify: ";
  //   printArray(arr, N);

  if (root != i) {
    swap(arr[i], arr[root]);
    heapify(arr, N, root);
  }
}

void heapSort(vector<int> &arr, int N) {
  //   int root = 0;
  for (int i = N / 2 - 1; i >= 0; i--) {
    heapify(arr, N, i);
  }
  int count = 1;
  for (int i = N - 1; i > 0; i--) {
    swap(arr[0], arr[i]);
    cout << "Pass " << count << ":\t";
    printArray(arr, N, i);
    count++;
    heapify(arr, i, 0);
  }
}

int main() {
  vector<int> arr = {};

  arr = {3, 9, 1, 12, 4, 6};
  int N = arr.size();
  cout << "Average Case\nOriginal Array: ";
  printArray(arr, N, __INT_MAX__);
  heapSort(arr, N);
  cout << "Sorted array: \t";
  printArray(arr, N, __INT_MAX__);

  arr = {2, 3, 4, 5, 8, 12};
  N = arr.size();
  cout << "Best Case\nOriginal Array: ";
  printArray(arr, N, __INT_MAX__);
  heapSort(arr, N);
  cout << "Sorted array: \t";
  printArray(arr, N, __INT_MAX__);

  arr = {12, 11, 9, 8, 5, 1};
  N = arr.size();
  cout << "Worst Case\nOriginal Array: ";
  printArray(arr, N, __INT_MAX__);
  heapSort(arr, N);
  cout << "Sorted array: \t";
  printArray(arr, N, __INT_MAX__);

  return 0;
}