#include <iostream>
#include <vector>
using namespace std;

int linear_search(vector<int> arr, int k) {
  int n = int(arr.size());
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
  int res = 0, key = 6;
  vector<int> arr = {2, 4, 5, 6, 7, 8, 11};
  res = linear_search(arr, key);
  print_message(res);
  return 0;
}