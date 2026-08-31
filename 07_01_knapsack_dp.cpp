#include <iostream>
using namespace std;

int main() {
    int n, W;

    cin >> n >> W;

    int weight[100], value[100];
    int dp[101][1001] = {};

    for (int i = 0; i < n; i++)
        cin >> weight[i];

    for (int i = 0; i < n; i++)
        cin >> value[i];

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {

            dp[i][w] = dp[i - 1][w];

            if (weight[i - 1] <= w) {
                dp[i][w] = max(
                    dp[i][w],
                    value[i - 1] +
                    dp[i - 1][w - weight[i - 1]]
                );
            }
        }
    }

    cout << "Maximum value = " << dp[n][W];

    return 0;
}
