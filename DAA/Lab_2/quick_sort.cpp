#include <iostream>
#include <vector>
using namespace std;

void print_arr(const vector<int> arr, int start, int end) {
  for (int i = start; i <= end; i++) cout << arr[i] << " ";
  cout << endl;
}

int part_arr(vector<int>& a, int low, int high) {
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

void quick_sort(vector<int>& a, int low, int high) {
  if (low < high) {
    int pivot = part_arr(a, low, high);
    cout << "Pivot: " << a[pivot] << endl;
    print_arr(a, low, high);
    quick_sort(a, low, pivot - 1);
    quick_sort(a, pivot + 1, high);
  }
}

int main() {
  vector<int> arr = {8, 1, 3, 7, 10, 6};
  quick_sort(arr, 0, 5);
  cout << "After Sorting:\n";
  print_arr(arr, 0, 5);
  return 0;
}
