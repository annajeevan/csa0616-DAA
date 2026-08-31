#include <iostream>
using namespace std;

int main() {
    int n, key;
    int a[1000];

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cin >> key;

    int low = 0;
    int high = n - 1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (a[mid] == key) {

            cout << "Element found at index "
                 << mid;

            return 0;
        }

        if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    cout << "Element not found";

    return 0;
}
