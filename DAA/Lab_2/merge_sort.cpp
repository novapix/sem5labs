#include <iostream>
#include <vector>
using namespace std;

void print_vec(const vector<int>& vec, int start, int end) {
  for (int i = start; i <= end; i++) {
    cout << vec[i] << " ";
  }
  cout << endl;
}

void merger(vector<int>& a, int first, int mid, int last) {
  int nl = mid - first + 1;
  int nr = last - mid;

  vector<int> left_arr(nl), right_arr(nr);

  for (int i = 0; i < nl; i++) left_arr[i] = a[first + i];
  for (int j = 0; j < nr; j++) right_arr[j] = a[mid + 1 + j];

  int i = 0, j = 0, k = first;

  while (i < nl && j < nr) {
    if (left_arr[i] <= right_arr[j]) {
      a[k] = left_arr[i];
      i++;
    } else {
      a[k] = right_arr[j];
      j++;
    }
    k++;
  }

  while (i < nl) {
    a[k] = left_arr[i];
    i++;
    k++;
  }

  while (j < nr) {
    a[k] = right_arr[j];
    j++;
    k++;
  }
}

void merge_sort(vector<int>& a, int first, int last) {
  if (first >= last) return;
  int mid = first + (last - first) / 2;

  print_vec(a, first, mid);
  merge_sort(a, first, mid);

  print_vec(a, mid + 1, last);
  merge_sort(a, mid + 1, last);

  merger(a, first, mid, last);

  cout << "Merged array is: ";
  print_vec(a, first, last);
}

int main() {
  vector<int> arr = {};
  cout << "\nAverage Case" << endl;
  arr = {5, 2, 8, 1, 3, 7};
  merge_sort(arr, 0, arr.size() - 1);
  cout << "Sorted array: ";
  print_vec(arr, 0, arr.size() - 1);

  cout << "------------------" << endl;

  cout << "\nBest Case" << endl;
  arr = {1, 2, 3, 4, 5, 7};
  merge_sort(arr, 0, arr.size() - 1);
  cout << "Sorted array: ";
  print_vec(arr, 0, arr.size() - 1);
  cout << "------------------" << endl;

  cout << "\nWorst Case" << endl;
  arr = {7, 6, 5, 4, 3, 1};
  merge_sort(arr, 0, arr.size() - 1);
  cout << "Sorted array: ";
  print_vec(arr, 0, arr.size() - 1);
  cout << "------------------" << endl;

  return 0;
}
