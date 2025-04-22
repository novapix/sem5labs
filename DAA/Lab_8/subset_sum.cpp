#include <iostream>
#include <vector>
using namespace std;

class SubsetSum {
 public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> res;
    vector<int> comb;
    makeCombination(candidates, target, 0, comb, 0, res);
    return res;
  }

 private:
  void makeCombination(vector<int> &candidates, int target, int idx,
                       vector<int> &comb, int total, vector<vector<int>> &res) {
    if (total == target) {
      res.push_back(comb);
      return;
    }

    if (total > target || idx >= int(candidates.size())) {
      return;
    }

    comb.push_back(candidates[idx]);
    makeCombination(candidates, target, idx + 1, comb, total + candidates[idx],
                    res);

    comb.pop_back();
    makeCombination(candidates, target, idx + 1, comb, total, res);
  }
};

int main() {
  SubsetSum solution;

  vector<int> candidates = {2, 3, 6, 7, 1, 4};
  int target = 8;

  vector<vector<int>> result = solution.combinationSum(candidates, target);

  cout << "Combinations that sum up to " << target << " are:" << endl;
  for (int r = 0; r < int(result.size()); ++r) {
    cout << "[";
    for (int i = 0; i < int(result[r].size()); ++i) {
      cout << result[r][i];
      if (i != int(result[r].size()) - 1) {
        cout << ", ";
      }
    }
    cout << "]" << endl;
  }

  return 0;
}
