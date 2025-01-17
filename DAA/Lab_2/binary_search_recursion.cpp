#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void print_arr(vector<int> arr, int start, int end) {
  for (int i = start; i <= end; i++) cout << arr[i] << " ";
  cout << endl;
}

bool check_sorted(vector<int> a) {
  for (int i = 0; i < int(a.size()) - 1; i++) {
    if (a[i] > a[i + 1]) return false;
  }
  return true;
}

int binary_search(vector<int> a, int l, int r, int k) {
  cout << "Current search array is: ";
  print_arr(a, l, r);
  if ((a[l] == a[r]) && (a[l] != k)) {
    cout << "Key not in list";
    return -1;
  }

  int mid = (l + r) / 2;
  cout << "At " << mid << " index, comparing " << a[mid] << " and " << k
       << "\n";
  if (a[mid] == k) {
    printf("Key found at index %d\n", mid);
    return 0;
  } else if (a[mid] > k)
    binary_search(a, l, mid - 1, k);
  else if (a[mid] < k)
    binary_search(a, mid + 1, r, k);
  return -1;
}

int main() {
  //   vector<int> arr = {1, 13, 9, 5, 4, 10};
  //   int key = 4;

  //   if (check_sorted(arr)) {
  //     binary_search(arr, 0, arr.size() - 1, key);
  //   } else {
  //     cout << "List not sorted.\n";
  //   }

  vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int key = 9;

  if (check_sorted(arr)) {
    binary_search(arr, 0, arr.size() - 1, key);
  } else {
    cout << "List not sorted.\n";
  }

  return 0;
}