#include <iostream>
#include <vector>
using namespace std;

void print_arr(const vector<int>& arr, int start, int end) {
  for (int i = start; i <= end; i++) cout << arr[i] << " ";
  cout << endl;
}

bool check_sorted(const vector<int>& a) {
  for (int i = 0; i < int(a.size()) - 1; i++) {
    if (a[i] > a[i + 1]) return false;
  }
  return true;
}

int binary_search(const vector<int>& a, int l, int r, int k) {
  cout << "Current search array is: ";
  print_arr(a, l, r);
  if (l > r) return -1;

  int mid = l + ((r - l) >> 1);
  cout << "At " << mid << " index, comparing " << a[mid] << " and " << k
       << "\n";
  if (a[mid] == k) {
    return mid;
  } else if (a[mid] > k) {
    return binary_search(a, l, mid - 1, k);
  } else {
    return binary_search(a, mid + 1, r, k);
  }
}

int main() {
  vector<int> arr = {};
  // arr = {1, 13, 9, 5, 4, 10};
  // int key = 4;
  // if (check_sorted(arr)) {
  //     binary_search(arr, 0, arr.size() - 1, key);
  // } else {
  //     cout << "List not sorted.\n";
  // }

  arr = {30, 35, 41, 52, 61, 70, 80, 88, 91, 97};
  int key = 91;

  if (check_sorted(arr)) {
    int res = binary_search(arr, 0, arr.size() - 1, key);
    cout << (res == -1 ? "Key is not in List\n"
                       : "Key found at index " + to_string(res) + "\n");
  } else {
    cout << "List not sorted.\n";
  }

  return 0;
}
