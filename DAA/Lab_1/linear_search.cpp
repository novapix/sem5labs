#include <iostream>
using namespace std;

int linear_search(int arr[], int n, int k) {
  for (int i = 0; i < n; i++) {
    cout << "At " << i << " index, comparing " << arr[i] << " and " << k
         << endl;

    if (arr[i] == k) {
      return i;
    }
  }
  return -1;
}
void print_message(int index) {
  cout << (index == -1 ? "Key not found in array"
                       : "Key Found in index " + to_string(index))
       << endl;
}

int main() {
  int res = 0;
  int arr_best[7] = {1, 5, 6, 7, 2, 3, 4}, k_b = 1;
  int arr_worst[7] = {5, 6, 7, 1, 2, 3, 4}, k_w = 10;
  int arr_avg[7] = {5, 6, 7, 1, 2, 3, 4}, k_a = 1;

  cout << "\nBest case: " << endl;
  res = linear_search(arr_best, 7, k_b);
  print_message(res);

  cout << "\nWorst case: " << endl;
  res = linear_search(arr_worst, 7, k_w);
  print_message(res);

  cout << "\nAverage case: " << endl;
  res = linear_search(arr_avg, 7, k_a);
  print_message(res);

  return 0;
}