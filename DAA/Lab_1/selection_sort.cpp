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

void selection_sort(vector<int>& a) {
  int n = a.size();
  for (int i = 0; i < n - 1; ++i) {
    int index = i;
    for (int j = i + 1; j < n; ++j) {
      if (a[j] < a[index]) {
        index = j;
      }
    }
    if (index != i) {
      swap(a[index], a[i]);
      cout << "Swapping " << a[i] << " with " << a[index] << endl;
    }

    cout << "Iteration " << i + 1 << ": ";
    print_arr(a);
  }
}

int main() {
  cout << "\nWorst Case:\n";
  vector<int> arr = {7, 1, 5, 3, 4, 6};
  selection_sort(arr);

  cout << "\nBest Case:\n";
  arr = {1, 2, 3, 4, 5, 7};
  selection_sort(arr);

  cout << "\nAvg Case:\n";
  arr = {1, 2, 5, 4, 3};
  selection_sort(arr);

  return 0;
}
