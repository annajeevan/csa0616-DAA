#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Item {
    double weight;
    double value;
    double ratio;
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {
    int n;
    double capacity;

    cin >> n >> capacity;

    Item item[100];

    for (int i = 0; i < n; i++) {

        cin >> item[i].weight
            >> item[i].value;

        item[i].ratio =
            item[i].value /
            item[i].weight;
    }

    sort(
        item,
        item + n,
        compare
    );

    double profit = 0;

    for (int i = 0;
         i < n && capacity > 0;
         i++) {

        double take =
            min(
                capacity,
                item[i].weight
            );

        profit +=
            take * item[i].ratio;

        capacity -= take;
    }

    cout << fixed
         << setprecision(2);

    cout << "Maximum Profit = "
         << profit;

    return 0;
}
