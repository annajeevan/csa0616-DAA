#include <iostream>
using namespace std;

int n, target;
int a[30];
bool selected[30];

bool subsetSum(int index, int sum) {

    if (sum == target)
        return true;

    if (index == n || sum > target)
        return false;

    selected[index] = true;

    if (subsetSum(
            index + 1,
            sum + a[index]))
        return true;

    selected[index] = false;

    if (subsetSum(
            index + 1,
            sum))
        return true;

    return false;
}

int main() {

    cin >> n >> target;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (subsetSum(0, 0)) {

        cout << "Subset: ";

        for (int i = 0; i < n; i++) {

            if (selected[i])
                cout << a[i] << " ";
        }

    } else {

        cout << "No subset found";
    }

    return 0;
}
