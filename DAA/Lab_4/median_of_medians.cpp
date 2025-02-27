#include <iostream>
#include <vector>
#define PARTITION_SIZE 5

using namespace std;

void printVectorofVector(const vector<vector<int>> &partVec) {
  for (auto innerVector : partVec) {
    for (int ele : innerVector) {
      cout << ele << " ";
    }
    cout << "\n";
  }
  cout << endl;
}

void printVector(const vector<int> &vec) {
  for (int ele : vec) {
    cout << ele << " ";
  }
  cout << "\n";
}

vector<vector<int>> partitionVectors(const vector<int> &vec) {
  vector<vector<int>> part;
  int size = int(vec.size());
  for (int i = 0; i < size; i += PARTITION_SIZE) {
    // cout << "OUTER=" << i << endl;
    vector<int> inner = {};
    for (int j = i; j < min(i + PARTITION_SIZE, size); j++) {
      // cout << "INNER=" << j << endl;
      inner.push_back(vec[j]);
    }
    part.push_back(inner);
  }
  return part;
}

void insertionSort(vector<int> &a) {
  int n = a.size();
  for (int i = 1; i < n; ++i) {
    int key = a[i];
    int j = i - 1;

    while (j >= 0 && a[j] > key) {
      a[j + 1] = a[j];
      j--;
    }

    a[j + 1] = key;
  }
}

void insertionVectorSort(vector<int> &medianArr, vector<vector<int>> &partVec) {
  int n = medianArr.size();

  // Start with the second element like Insertion Sort
  // But Instead of just elements we swap Vectors as well
  for (int i = 1; i < n; ++i) {
    int key = medianArr[i];
    // Corresponding vector in partVec according to i
    vector<int> keyVec = partVec[i];
    int j = i - 1;

    // Insert Element as well as Vector to Correct Position
    while (j >= 0 && medianArr[j] > key) {
      medianArr[j + 1] = medianArr[j];
      partVec[j + 1] = partVec[j]; // Shift the corresponding vector in partVec
      j--;
    }

    medianArr[j + 1] = key;
    // Place the corresponding vector in the correct position
    partVec[j + 1] = keyVec;
  }
}

int findMedianOfMedians(vector<int> &arr, int l, int r) {
  // PASS COPY OF OG VECTOR WITH SPECIFIED L R POINTS
  vector<vector<int>> partVec =
      partitionVectors(vector<int>(arr.begin() + l, arr.begin() + r + 1));

  vector<int> medians;
  for (auto &innerVector : partVec) {
    insertionSort(innerVector);
    medians.push_back(innerVector[innerVector.size() / 2]);
  }

  insertionVectorSort(medians, partVec);
  cout << endl;
  cout << "Sorted Partitioned Vectors: " << endl;

  printVectorofVector(partVec);
  cout << "Medians Vector: ";
  printVector(medians);
  return medians[medians.size() / 2];
}

int part(vector<int> &arr, int l, int r, int x) {
  int pivotIdx = l;
  for (int i = l; i < r; i++) {
    if (arr[i] == x) {
      pivotIdx = i;
      break;
    }
  }
  swap(arr[pivotIdx], arr[r]);

  int i = l;
  for (int j = l; j < r; j++) {
    if (arr[j] < x) {
      swap(arr[i], arr[j]);
      i++;
    }
  }
  swap(arr[i], arr[r]);
  return i;
}

int nthOrderStatistic(vector<int> &original, int l, int r, int n) {
  if (l == r)
    return original[l];
  int medianOfMedians = findMedianOfMedians(original, l, r);
  cout << "Median of Median: " << medianOfMedians << endl << endl;
  int pivotIndex = part(original, l, r, medianOfMedians);

  int k = pivotIndex - l + 1;

  if (n == k) {
    return original[pivotIndex];
  } else if (n < k) {
    cout << "n=" << n << " k=" << k << " Going Left" << endl;
    return nthOrderStatistic(original, l, pivotIndex - 1, n);
  } else {
    cout << "n=" << n << " k=" << k << " Going Right" << endl;
    return nthOrderStatistic(original, pivotIndex + 1, r, n - k);
  }
}

int main() {
  vector<int> vec;
  vec = {25, 24, 45, 58, 30, 61, 63, 68, 2, 98, 4, 15, 69, 20};
  int n;
  cout << "Enter the nth element to find: ";
  cin >> n;
  if (n < 1 || n > int(vec.size())) {
    cout << "Invalid.. Exiting" << endl;
    exit(1);
  }
  int dummy = nthOrderStatistic(vec, 0, vec.size() - 1, n);
  cout << n << "th Element is:" << dummy << endl;
  return 0;
}
