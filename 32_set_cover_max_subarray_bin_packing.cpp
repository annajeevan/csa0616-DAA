#include <iostream>
#include <algorithm>
using namespace std;

void setCover() {

    int sets, elements;

    cin >> sets >> elements;

    int a[50][50] = {};

    for (int i = 0; i < sets; i++)
        for (int j = 0; j < elements; j++)
            cin >> a[i][j];

    bool covered[50] = {};

    int remaining = elements;

    cout << "Selected Sets: ";

    while (remaining > 0) {

        int best = -1;
        int bestCount = 0;

        for (int i = 0; i < sets; i++) {

            int count = 0;

            for (int j = 0; j < elements; j++) {

                if (a[i][j] &&
                    !covered[j]) {

                    count++;
                }
            }

            if (count > bestCount) {

                bestCount = count;
                best = i;
            }
        }

        if (best == -1)
            break;

        cout << best << " ";

        for (int j = 0; j < elements; j++) {

            if (a[best][j] &&
                !covered[j]) {

                covered[j] = true;
                remaining--;
            }
        }
    }

    cout << endl;
}

void maximumSubarray() {

    int n;
    int a[1000];

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int current = a[0];
    int best = a[0];

    for (int i = 1; i < n; i++) {

        current =
            max(
                a[i],
                current + a[i]
            );

        best =
            max(best, current);
    }

    cout << "Maximum Subarray Sum = "
         << best << endl;
}

void binPacking() {

    int n, capacity;

    cin >> n >> capacity;

    int item[1000];
    int bin[1000] = {};

    for (int i = 0; i < n; i++)
        cin >> item[i];

    int bins = 0;

    for (int i = 0; i < n; i++) {

        int j;

        for (j = 0; j < bins; j++) {

            if (bin[j] + item[i]
                <= capacity) {

                bin[j] += item[i];
                break;
            }
        }

        if (j == bins) {

            bin[bins] = item[i];
            bins++;
        }
    }

    cout << "Number of bins = "
         << bins << endl;
}

int main() {

    int choice;

    cout << "1. Set Cover\n";
    cout << "2. Maximum Subarray\n";
    cout << "3. Bin Packing\n";

    cin >> choice;

    if (choice == 1)
        setCover();

    else if (choice == 2)
        maximumSubarray();

    else if (choice == 3)
        binPacking();

    else
        cout << "Invalid choice";

    return 0;
}
