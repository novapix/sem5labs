#include <algorithm>  // For std::swap
#include <iostream>
#include <vector>
using namespace std;

void print_arr(const vector<int>& a) {
  for (int elem : a) {
    cout << elem << " ";
  }
  cout << endl;
}

void bubble_sort(vector<int>& a) {
  int n = a.size();
  for (int i = 0; i < n; ++i) {
    bool swapped = false;
    cout << "Iteration " << i + 1 << ": ";
    for (int j = 0; j < n - i - 1; j++) {
      if (a[j] > a[j + 1]) {
        swap(a[j], a[j + 1]);
        cout << "\n" << a[j] << " <--> " << a[j + 1];
        swapped = true;
      }
    }
    if (!swapped) {
      cout << "\nArray is already sorted. Exiting early.\n";
      break;
    }
    cout << "\n";
    print_arr(a);
  }
}

int main() {
  cout << "\nWorst Case:\n";
  vector<int> arr = {7, 6, 5, 4, 3, 1};
  bubble_sort(arr);

  cout << "\nBest Case:\n";
  arr = {1, 2, 3, 4, 5, 7};
  bubble_sort(arr);

  cout << "\nAvg Case:\n";
  arr = {1, 2, 5, 4, 3};
  bubble_sort(arr);

  return 0;
}
