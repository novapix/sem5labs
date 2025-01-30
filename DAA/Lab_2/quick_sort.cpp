#include <iostream>
#include <vector>
using namespace std;

void printArr(const vector<int>& arr, int start, int end) {
  for (int i = start; i <= end; i++) cout << arr[i] << " ";
  cout << endl;
}

int partitionArr(vector<int>& a, int low, int high) {
  int pivot = a[high];
  int i = low - 1;

  for (int j = low; j <= high - 1; j++) {
    if (a[j] < pivot) {
      i++;
      swap(a[i], a[j]);
    }
  }
  swap(a[i + 1], a[high]);
  return (i + 1);
}

void quick_sort(vector<int>& a, int low, int high, int pass = 1) {
  if (low < high) {
    cout << "\nPass: " << pass << "\n";
    printArr(a, low, high);
    int pivot = partitionArr(a, low, high);
    cout << "Pivot: " << a[pivot] << endl;
    cout << "Left: ";
    printArr(a, low, pivot - 1);
    cout << "Right: ";
    printArr(a, pivot + 1, high);
    quick_sort(a, low, pivot - 1, pass + 1);
    quick_sort(a, pivot + 1, high, pass + 1);
  }
}

int main() {
  vector<int> arr = {};

  cout << "\nBest Case" << endl;
  arr = {5, 2, 8, 1, 3, 7};
  quick_sort(arr, 0, arr.size() - 1);
  cout << "After Sorting:\t";
  printArr(arr, 0, arr.size() - 1);
  cout << "---------------------------------------------" << endl;

  cout << "\nAvg Case" << endl;
  arr = {10, 2, 30, 40, 5, 7};
  quick_sort(arr, 0, arr.size() - 1);
  cout << "After Sorting:\t";
  printArr(arr, 0, arr.size() - 1);
  cout << "---------------------------------------------" << endl;

  cout << "\nWorst Case" << endl;
  arr = {7, 6, 5, 4, 3, 1};
  quick_sort(arr, 0, arr.size() - 1);
  cout << "After Sorting:\t";
  printArr(arr, 0, arr.size() - 1);

  return 0;
}
