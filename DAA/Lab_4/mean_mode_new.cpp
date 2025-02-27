#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void bubble_sort(vector<int> &a) {
  int n = a.size();
  for (int i = 0; i < n; ++i) {
    bool swapped = false;
    for (int j = 0; j < n - i - 1; j++) {
      if (a[j] > a[j + 1]) {
        swap(a[j], a[j + 1]);
        swapped = true;
      }
    }
    if (!swapped)
      break;
  }
}

int main() {
  vector<int> a = {25, 24, 45, 58, 30, 61, 63, 68, 98, 4, 15, 69, 30};
  int n = int(a.size());
  float mean = 0.0, median = 0.0;

  for (int i = 0; i < n; i++)
    mean += a[i];
  mean = mean / n;

  bubble_sort(a);

  median = (n % 2 == 0) ? 0.5 * (a[n / 2] + a[n / 2 - 1]) : a[n / 2];

  unordered_map<int, int> frequency;
  int mode = a[0], max_count = 1;

  for (int i = 0; i < n; i++) {
    frequency[a[i]]++;
    if (frequency[a[i]] > max_count) {
      max_count = frequency[a[i]];
      mode = a[i];
    }
  }

  printf("\nMean = %.3f", mean);
  printf("\nMedian = %.3f", median);
  printf("\nMode = %d", mode);

  return 0;
}
