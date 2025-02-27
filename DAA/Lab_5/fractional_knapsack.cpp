#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void printRatioTable(vector<int> item, vector<int> val, vector<int> w,
                     vector<double> ratio, int n) {
  cout << "Item\t" << "Weight\t" << "Value\t" << "Ratio" << endl;
  for (int i = 0; i < n; i++) {
    cout << item[i] << "\t" << w[i] << "\t" << val[i] << "\t" << ratio[i]
         << "\n";
  }
  cout << endl;
}

void fractional_knapsack(vector<int> val, vector<int> w, int capacity, int n) {
  vector<int> item(n);
  for (int i = 0; i < n; i++) {
    item[i] = i + 1;
  }

  vector<double> ratio(n);
  for (int i = 0; i < n; i++) {
    ratio[i] = (double)val[i] / w[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (ratio[i] < ratio[j]) {
        swap(ratio[i], ratio[j]);
        swap(val[i], val[j]);
        swap(w[i], w[j]);
        swap(item[i], item[j]);
      }
    }
  }
  printRatioTable(item, val, w, ratio, n);

  double max_value = 0;
  double last_item_fraction = 0;
  int last_item = 0;
  for (int i = 0; i < n; i++) {
    if (capacity - w[i] >= 0) {
      cout << "Adding Item " << item[i] << " to Sack(Weight " << w[i] << ")"
           << endl;
      capacity -= w[i];
      max_value += val[i];
      cout << "Remaining Capacity: " << capacity << endl;
      last_item = i;
    } else if (capacity > 0) {
      last_item_fraction = (double)capacity / w[i];
      max_value += val[i] * last_item_fraction;
      cout << "Adding Fraction of Item " << item[i] << " to Sack" << endl;
      capacity = 0;
      last_item = i;
      break;
    }
  }

  cout << "Maximum value: " << max_value << endl;
  cout << "The items in the knapsack are:\n";
  for (int i = 0; i <= last_item; i++) {
    if (capacity == 0 && i == last_item) {
      double fraction = (double)val[i] * last_item_fraction;
      cout << "Item " << item[i] << " Fractional Weight "
           << last_item_fraction * w[i] << " Fractional Price: " << fraction
           << endl;
    } else {
      cout << "Item " << item[i] << " Weight " << w[i] << " Price " << val[i]
           << endl;
    }
  }
}

int main() {
  vector<int> weights = {1, 5, 5, 3, 100, 5, 10};
  vector<int> values = {10, 20, 20, 30, 60, 25, 50};

  int capacity;
  int n = weights.size();

  cout << "Enter the capacity of the knapsack: ";
  cin >> capacity;

  fractional_knapsack(values, weights, capacity, n);
  return 0;
}
