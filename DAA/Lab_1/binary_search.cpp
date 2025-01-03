#include <iostream>
using namespace std;

void print_message(int index) {
  cout << (index == -1 ? "Key not found in array"
                       : "Key Found in index " + to_string(index))
       << endl;
}

int binary_search(int arr[], int n, int k) {
  int mid, right = n - 1, left = 0;
  while (left <= right) {
    mid = (right + left) / 2;
    printf("Left=%d, Right=%d, Mid=%d\n", left, right, mid);
    if (k < arr[mid])
      right = mid - 1;
    else if (k > arr[mid])
      left = mid + 1;
    else if (arr[mid] == k) {
      return mid;
    }
    printf("Compared key with %d\n", arr[mid]);
  }
  return -1;
}

int main() {
  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, k = 9;
  // k = 5;
  //   k = 11;
  int res = binary_search(arr, 10, k);
  print_message(res);
  return 0;
}