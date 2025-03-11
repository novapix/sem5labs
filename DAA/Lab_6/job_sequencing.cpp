#include <cstdio>
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
  if (parent[slot] == -1) return slot;
  return parent[slot] = findSlot(parent, parent[slot]);  // Path compression
}

void jobScheduling(vector<Job> &jobs) {
  int n = jobs.size();

  cout << "Available Jobs:\n";
  printJobsTable(jobs);

  bubbleSort(jobs);

  cout << "After Sorting Jobs By Profit:" << endl;
  printJobsTable(jobs);

  int maxDeadline = 0;
  for (int i = 0; i < n; i++) {
    if (jobs[i].deadLine > maxDeadline) maxDeadline = jobs[i].deadLine;
  }

  vector<int> parent(maxDeadline + 1, -1);

  vector<char> result(maxDeadline, ' ');
  int maxProfit = 0;

  cout << "\nJob Selection Process:\n";

  for (int i = 0; i < n; i++) {
    int availableSlot = findSlot(parent, jobs[i].deadLine);

    if (availableSlot > 0) {
      result[availableSlot - 1] = jobs[i].id;
      maxProfit += jobs[i].profit;
      parent[availableSlot] = findSlot(parent, availableSlot - 1);
      //   cout << "Job " << jobs[i].id << " scheduled at slot " <<
      //   availableSlot
      //        << " (Profit: " << jobs[i].profit << ")\n";
      printf("Job %c scheduled at slot %d (Profit: %d)\n", jobs[i].id,
             availableSlot, jobs[i].profit);

    } else {
      cout << "Job " << jobs[i].id << " skipped (Deadline Missed)\n";
    }
  }

  cout << "\nFinal Job Sequence (Max Profit Order): ";
  for (int i = 0; i < maxDeadline; i++) {
    if (result[i] != ' ') {
      cout << result[i] << " ";
    }
  }
  cout << "\nTotal Profit: " << maxProfit << endl;
}

int main() {
  vector<Job> jobs = {
      {'a', 1, 10}, {'b', 1, 15}, {'c', 2, 133}, {'d', 3, 17}, {'e', 3, 21}};

  jobScheduling(jobs);
  return 0;
}
