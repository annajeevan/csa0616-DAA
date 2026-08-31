#include <iostream>
using namespace std;

void findMinMax(
    int a[],
    int low,
    int high,
    int &minimum,
    int &maximum
) {

    if (low == high) {

        minimum = maximum = a[low];
        return;
    }

    if (high == low + 1) {

        if (a[low] < a[high]) {
            minimum = a[low];
            maximum = a[high];
        } else {
            minimum = a[high];
            maximum = a[low];
        }

        return;
    }

    int mid = (low + high) / 2;

    int min1, max1;
    int min2, max2;

    findMinMax(a, low, mid, min1, max1);
    findMinMax(a, mid + 1, high, min2, max2);

    minimum = min(min1, min2);
    maximum = max(max1, max2);
}

int main() {
    int n;
    int a[1000];

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int minimum, maximum;

    findMinMax(
        a,
        0,
        n - 1,
        minimum,
        maximum
    );

    cout << "Minimum = " << minimum << endl;
    cout << "Maximum = " << maximum << endl;

    return 0;
}
