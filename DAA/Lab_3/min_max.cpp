#include <iostream>
#include <vector>
using namespace std;

void printArr(const vector<int> &arr, int start, int end) {
  for (int i = start; i <= end; i++) cout << arr[i] << " ";
  cout << endl;
}

int findMaxMin(const vector<int> &a, int low, int high, int &Max, int &Min,
               int pass = 1) {
  if (low == high) {
    Max = a[low];
    Min = a[low];
    return 0;
  }
  int leftMax, leftMin, rightMax, rightMin;
  int mid = (low + high) / 2;
  cout << "\nPass:" << pass << endl;
  cout << "Search Interval:\t";
  printArr(a, low, high);
  cout << "Left Half: ";
  printArr(a, low, mid);
  cout << "Right Half: ";
  printArr(a, mid + 1, high);

  findMaxMin(a, low, mid, leftMax, leftMin, pass + 1);
  findMaxMin(a, mid + 1, high, rightMax, rightMin, pass + 1);

  Max = (leftMax > rightMax) ? leftMax : rightMax;
  Min = (leftMin < rightMin) ? leftMin : rightMin;
  cout << "Max = " << Max << ' ';
  cout << "Min = " << Min << endl;

  return 0;
}

int main() {
  vector<int> arr = {74, 13, 98, 32, 57, 5, 83, 61, 27, 49};
  int Max, Min;

  findMaxMin(arr, 0, arr.size() - 1, Max, Min);
  cout << endl;
  cout << "The minimum value in the list is " << Min << endl;
  cout << "The maximum value in the list is " << Max << endl;

  return 0;
}