#include <iostream>
using namespace std;

int main() {
    int n;

    cin >> n;

    int e[2], x[2];

    int a[2][100];
    int t[2][100];

    cin >> e[0] >> e[1];
    cin >> x[0] >> x[1];

    for (int i = 0; i < n; i++)
        cin >> a[0][i];

    for (int i = 0; i < n; i++)
        cin >> a[1][i];

    for (int i = 0; i < n - 1; i++)
        cin >> t[0][i];

    for (int i = 0; i < n - 1; i++)
        cin >> t[1][i];

    int f1 = e[0] + a[0][0];
    int f2 = e[1] + a[1][0];

    for (int i = 1; i < n; i++) {

        int newF1 =
            min(
                f1 + a[0][i],
                f2 + t[1][i - 1] + a[0][i]
            );

        int newF2 =
            min(
                f2 + a[1][i],
                f1 + t[0][i - 1] + a[1][i]
            );

        f1 = newF1;
        f2 = newF2;
    }

    int answer =
        min(
            f1 + x[0],
            f2 + x[1]
        );

    cout << "Minimum time = "
         << answer;

    return 0;
}
