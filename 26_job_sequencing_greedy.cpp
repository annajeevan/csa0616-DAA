#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    int n;

    cin >> n;

    Job jobs[100];

    int maxDeadline = 0;

    for (int i = 0; i < n; i++) {

        cin >> jobs[i].id
            >> jobs[i].deadline
            >> jobs[i].profit;

        maxDeadline =
            max(
                maxDeadline,
                jobs[i].deadline
            );
    }

    sort(
        jobs,
        jobs + n,
        compare
    );

    bool used[101] = {};
    char slot[101];

    int totalProfit = 0;

    for (int i = 0; i < n; i++) {

        for (int j =
             min(maxDeadline,
                 jobs[i].deadline);
             j >= 1;
             j--) {

            if (!used[j]) {

                used[j] = true;
                slot[j] = jobs[i].id;

                totalProfit +=
                    jobs[i].profit;

                break;
            }
        }
    }

    cout << "Job sequence: ";

    for (int i = 1;
         i <= maxDeadline;
         i++) {

        if (used[i])
            cout << slot[i] << " ";
    }

    cout << "\nMaximum Profit = "
         << totalProfit;

    return 0;
}
