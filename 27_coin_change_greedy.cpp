#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, amount;

    cin >> n >> amount;

    int coins[100];

    for (int i = 0; i < n; i++)
        cin >> coins[i];

    sort(
        coins,
        coins + n,
        greater<int>()
    );

    int count = 0;

    cout << "Coins used: ";

    for (int i = 0; i < n; i++) {

        while (amount >= coins[i]) {

            cout << coins[i] << " ";

            amount -= coins[i];

            count++;
        }
    }

    if (amount != 0) {

        cout << "\nExact change not possible";

    } else {

        cout << "\nNumber of coins = "
             << count;
    }

    return 0;
}
