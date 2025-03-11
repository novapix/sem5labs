#include <iostream>
#include <vector>
using namespace std;

struct Job {
  char id;
  int deadLine;
  int profit;
};

void printJobsTable(const vector<Job> &jobs) {
  int n = jobs.size();
  cout << "ID\tDeadline\tProfit" << endl;
  for (int i = 0; i < n; i++) {
    printf("%c\t%d\t\t%d\n", jobs[i].id, jobs[i].deadLine, jobs[i].profit);
  }
}

void displayParentVector(const vector<int> &parent) {
  cout << "Parent vector: [";
  for (int i = 0; i < parent.size(); i++) {
    cout << (i > 0 ? ", " : "") << i << ":" << parent[i];
  }
  cout << "]" << endl;
}

void customSwap(Job &a, Job &b) {
  Job temp = a;
  a = b;
  b = temp;
}

void bubbleSort(vector<Job> &jobs) {
  int n = jobs.size();
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (jobs[j].profit < jobs[j + 1].profit) {
        customSwap(jobs[j], jobs[j + 1]);
      }
    }
  }
}

// USE PATH COMPRESSION TO DIRECTLY FIND THE ROOT
int findSlot(vector<int> &parent, int slot) {
  cout << "  findSlot(" << slot << ") called" << endl;

  if (parent[slot] == -1) {
    cout << "    Slot " << slot << " is available, returning it" << endl;
    return slot;
  }

  cout << "    Slot " << slot << " is not available, following link to "
       << parent[slot] << endl;
  int result = findSlot(parent, parent[slot]);
  cout << "    Path compression: updating parent[" << slot << "] = " << result
       << endl;
  parent[slot] = result;  // Path compression
  return result;
}

void jobScheduling(vector<Job> &jobs) {
  int n = jobs.size();
  cout << "Available Jobs:\n";
  printJobsTable(jobs);

  bubbleSort(jobs);

  cout << "\nJobs after sorting by profit (descending):\n";
  printJobsTable(jobs);

  int maxDeadline = 0;
  for (int i = 0; i < n; i++) {
    if (jobs[i].deadLine > maxDeadline) maxDeadline = jobs[i].deadLine;
  }

  vector<int> parent(maxDeadline + 1, -1);
  vector<char> result(maxDeadline, ' ');
  int maxProfit = 0;

  cout << "\nInitial parent vector (all -1 means all slots available):" << endl;
  displayParentVector(parent);

  cout << "\nJob Selection Process:\n";
  for (int i = 0; i < n; i++) {
    cout << "\nProcessing Job " << jobs[i].id
         << " (Deadline: " << jobs[i].deadLine << ", Profit: " << jobs[i].profit
         << ")" << endl;

    int availableSlot = findSlot(parent, jobs[i].deadLine);

    if (availableSlot > 0) {
      result[availableSlot - 1] = jobs[i].id;
      maxProfit += jobs[i].profit;

      cout << "  Finding next available slot: findSlot(" << availableSlot - 1
           << ")" << endl;
      int nextAvailable = findSlot(parent, availableSlot - 1);
      parent[availableSlot] = nextAvailable;

      cout << "  Job " << jobs[i].id << " scheduled at slot " << availableSlot
           << " (Profit: " << jobs[i].profit << ")" << endl;
      cout << "  Updated parent[" << availableSlot << "] = " << nextAvailable
           << endl;
    } else {
      cout << "  Job " << jobs[i].id << " skipped (No slot available)" << endl;
    }

    cout << "  Current parent vector:" << endl;
    displayParentVector(parent);
  }

  cout << "\nFinal Job Sequence: ";
  for (int i = 0; i < maxDeadline; i++) {
    if (result[i] != ' ') {
      cout << result[i] << " ";
    }
  }
  cout << "\nTotal Profit: " << maxProfit << endl;
}

int main() {
  vector<Job> jobs = {
      {'a', 1, 100}, {'b', 1, 15}, {'c', 2, 133}, {'d', 3, 17}, {'e', 3, 21}};
  jobScheduling(jobs);
  return 0;
}
/*
USE THIS FOR IN DEPTH EXPLAINATION
PREVIOUS JOBS KEEP UPDATING THE NEXT AVAILABLE SLOT
*/