#include <iostream>
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
    if (!swapped) {
      break;
    }
  }
}

int main() {
  int n, int mode = 0;
  float mean = 0.0, median = 0.0;

  vector<int> a = {25, 24, 45, 58, 30, 61, 63, 68, 2, 98, 4, 15, 69};

  n = int(a.size());
  for (int i = 0; i < n; i++)
    mean += a[i];
  mean = mean / n;

  bubble_sort(a);

  median = (n % 2 == 0) ? 0.5 * (a[n / 2] + a[(n + 2) / 2]) : a[n / 2];

  int max_count = 1, count = 1;
  mode = a[0];
  for (int i = 1; i < n; i++) {
    if (a[i] == a[i - 1])
      count++;
    else
      count = 1;

    if (count > max_count) {
      max_count = count;
      mode = a[i];
    }
  }

  printf("\nMean = %.3f", mean);
  printf("\nMedian = %.3f", median);
  printf("\nMode = %d", mode);

  return 0;
}
