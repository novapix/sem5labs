#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void print_arr(const vector<int>& a) {
  for (int elem : a) {
    cout << elem << " ";
  }
  cout << endl;
}

void insertion_sort(vector<int>& a) {
  int n = a.size();
  for (int i = 1; i < n; ++i) {
    int key = a[i];
    int j = i - 1;

    while (j >= 0 && a[j] > key) {
      a[j + 1] = a[j];
      j--;
    }

    a[j + 1] = key;
    cout << "Inserting " << key << " at index " << j + 1 << endl;
    cout << "Iteration " << i << ": ";
    print_arr(a);
  }
}

int main() {
  cout << "\nWorst Case:\n";
  vector<int> arr = {7, 1, 5, 3, 4, 6};
  insertion_sort(arr);

  cout << "\nBest Case:\n";
  arr = {1, 2, 3, 4, 5, 7};
  insertion_sort(arr);

  cout << "\nAvg Case:\n";
  arr = {1, 2, 5, 4, 3};
  insertion_sort(arr);

  return 0;
}
